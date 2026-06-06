import requests

def fetchData(endpoint, filters={}):
    url = f"https://rickandmortyapi.com/api/{endpoint}"
    response = requests.get(url, params=filters)

    return response.json() if response.status_code == 200 else None


characters = fetchData("character", {"name": "Morty"})

if characters:
    for character in characters["results"]:
        print(character["name"])
else:
    print("Failed to fetch data")