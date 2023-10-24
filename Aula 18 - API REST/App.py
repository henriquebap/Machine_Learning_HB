from flask import Flask, request, jsonify
from warnings import filterwarnings
from joblib import load
filterwarnings('ignore')

def importa_modelo():
  modelo = load(open('./meu_modelo_serializado.joblib', 'rb'))

app = Flask(__name__)

modelo = importa_modelo()

@app.route('/predict', methods=['POST'])
def home():
  dados_post = request.get_json()
  dados = [dados_post[i] for i in ['Comprimento do Abdômen','Comprimento das Antenas']]
  resultado = modelo.predict([dados])[0]
  print(resultado)

  return jsonify(resultado = str(resultado))

app.run(
  debug = True,
  port = '5000',
)
