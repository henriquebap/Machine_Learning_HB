#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <DHT.h>

// Credenciais da rede WiFi
const char* ssid = "Hbap iPhone";
const char* password = "Criacao123*";

// Definição do pino e tipo do sensor DHT
#define DHTPIN 17      // GPIO onde o DHT11 está conectado (TX2)
#define DHTTYPE DHT11  // Sensor DHT11

// Inicializa o sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Cria o objeto server para a porta 80
AsyncWebServer server(80);

// Variáveis para armazenar os valores de temperatura e umidade
float temperature;
float humidity;

// Função para obter os valores de temperatura e umidade em formato JSON
String getSensorData() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Verifica se houve falha na leitura do sensor
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return "{\"temperature\":\"N/A\",\"humidity\":\"N/A\"}";
  }

  // Cria a string JSON
  String json = "{\"temperature\":";
  json += String(temperature);
  json += ",\"humidity\":";
  json += String(humidity);
  json += "}";

  return json;
}

// Código da página web que apresentará os valores:
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css">
  <style>
    body { font-family: Arial, sans-serif; text-align: center; background-color: #f4f4f4; margin: 0; padding: 20px; }
    .container { display: inline-block; background-color: white; border-radius: 10px; padding: 20px; box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.2); }
    h1 { color: #333; }
    p { font-size: 1.5rem }
    .temp { color: #e74c3c; }
    .humidity { color: #3498db; }
  </style>
</head>
<body>
  <div class="container">
    <h1>ESP32 Sensor Readings</h1>
    <p>Temperature: <span class="temp" id="temperature">--</span>C</p>
    <p>Humidity: <span class="humidity" id="humidity">--</span> %</p>
  </div>
  <script>
    setInterval(function(){
    fetch("/data").then(response => response.json()).then(data => {
    document.getElementById("temperature").textContent = data.temperature;
    document.getElementById("humidity").textContent = data.humidity;
    });
    }, 5000);
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  // Inicializa o sensor DHT
  dht.begin();

  // Conecta ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi..");
  }

  // Endereço IP do ESP32
  Serial.println(WiFi.localIP());

  // Rota para a página principal
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", index_html);
  });

  // Rota para obter os dados do sensor em formato JSON
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest* request) {
    String json = getSensorData();
    request->send(200, "application/json", json);
  });

  // Inicia o servidor
  server.begin();
}

void loop() {
  // Nada para fazer no loop, o servidor cuida de tudo
}