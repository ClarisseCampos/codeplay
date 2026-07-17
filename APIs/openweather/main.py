import os
import requests
from dotenv import load_dotenv

# carrega as variáveis salvas no .env 
load_dotenv()

lat = -29.376
lon = -51.114

# busca a key escondida no .venv
api_key = os.getenv("OPENWEATHER_API_KEY")

# verifica se a api_key foi encontrada
if not api_key:
    print("Erro: A chave OPENWEATHER_API_KEY não foi encontrada no arquivo .env!")
    exit()


url = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api_key}&units=metric&lang=pt_br"

try:
    response = requests.get(url)

    if response.status_code == 200:
        dados = response.json()

        cidade = dados['name']
        temp = dados['main']['temp']
        clima = dados['weather'][0]['description']
        humidade = dados['main']['humidity']

        print(f"\n🌍 Cidade: {cidade}")
        print(f"🌡️ Temperatura: {temp}°C")
        print(f"☁️ Condição: {clima.capitalize()}")
        print(f"💧 Umidade: {humidade}%\n")
    else:
        print(f"Erro na API. Status Code: {response.status_code}")

except Exception as e:
    print(f"Ocorreu um erro ao conectar: {e}")