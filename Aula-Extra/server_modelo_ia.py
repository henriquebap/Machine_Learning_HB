from flask import Flask, request, jsonify
import numpy as np
import pickle

app = Flask(__name__)

# Load the trained model from the file
model_file_path = 'D:/Machine_Learning_HB/Aula-Extra/modelo_treinado_gafesp.pickle'
try:
    with open(model_file_path, 'rb') as f:
        modelo = pickle.load(f)
except FileNotFoundError:
    print(f"Error: Model file not found at {model_file_path}")
    modelo = None

@app.route('/prever', methods=['GET'])
def prever():
    if modelo is None:
        return jsonify({'error': 'Model not available'}), 500

    comp_abd = request.args.get('comp_abd')
    comp_ant = request.args.get('comp_ant')

    if comp_abd is None or comp_ant is None:
        return jsonify({'error': 'Missing parameters'}), 400

    try:
        parametro1 = float(comp_abd)
        parametro2 = float(comp_ant)
    except ValueError:
        return jsonify({'error': 'Invalid parameter values'}), 400

    entrada = np.array([[parametro1, parametro2]])
    resultado = modelo.predict(entrada)

    return jsonify({'previsao': resultado.tolist()}), 200

if __name__ == '__main__':
    print("Flask server is running")
    app.run(debug=True)
