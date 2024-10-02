// Digite "thinger.io" no Library Manager.
// Instale a biblioteca thinger.io (by Alvaro Luis Bustamante)
#include <ThingerESP32.h>

// Digite "dht sensor library" no Library Manager.
// Instale a biblioteca DHT sensor (library by Adafruit)
#include <DHT.h>

// Insira as credenciais do dispositivo configurado na plataforma:
#define USERNAME "henriquebap"           // Seu nome de usuário na plataforma thinger.io
#define DEVICE_ID "Arduino"          // Device ID criado na plataforma
#define DEVICE_CREDENTIAL "Wq4GfTR7"  // Credencial do device criada na plataforma

// Insira as credenciais da sua rede WiFi 4G:
// Utilize um roteador de um celular próximo.
// No Android, certifique-se de deixar a frequência em 2.4GHz
// No iPhone, certifique-se de habilitar a opção "Maximizar Compatibilidade"
#define SSID "Hbap iPhone" 
#define SSID_PASSWORD "Criacao123*"

// Define the DHT pin and type
#define DHTPIN 17          // Pin where the DHT is connected
#define DHTTYPE DHT11    // DHT 17

DHT dht(DHTPIN, DHTTYPE);
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Crie aqui suas variáveis:
float temp, umid;              // Para sensor DHT11
int numero;                    // Número randômico
String ID = "“ESP32 2TDSPK Rm97796"; // Identificador

void setup() {  
  Serial.begin(115200);  
  thing.add_wifi(SSID, SSID_PASSWORD);
  dht.begin();
  delay(500);

  // Adicione os nomes dos Devices Resources à esquerda
  // e as variáveis do seu código à direita
thing["Temp"] >> outputValue(temp); 
thing["Humi"] >> outputValue(umid); 
thing["Random Num"] >> outputValue(numero); 
thing["ID"] >> outputValue(ID);  
}

void loop() {

  // Chamada da função para gerar o número randômico.
  geraNumero();

  // Chamada da função para leitura de temperatura e umidade do sensor.
  leituraSensor();

  // Essa função é responsável pela comunicação com a plataforma:
  thing.handle();
  // A requisição ocorrerá a cada 5 segundos.
  delay(5000);
}

void geraNumero(){
  // Crie aqui sua função para gerar o número randômico
  numero = random(0, 100);
}

void leituraSensor(){
  // Crie aqui sua função para ler os valores de temperatura e umidade do sensor DHT

  umid = dht.readHumidity();            // Read humidity
  temp = dht.readTemperature();         // Read temperature in Celsius

  // Check if any reads failed
  if (isnan(umid) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}



