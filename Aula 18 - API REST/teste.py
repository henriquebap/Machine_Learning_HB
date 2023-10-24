from requests import post

url = 'http://127.0.0.1:5000/predict'

dict_json = {
  "Comprimento do Abdômen": 0.5,
  "Comprimento das Antenas": 7.0,
}

r = post(url, json=dict_json)

print(r.json())
