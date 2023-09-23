from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
import subprocess

# Create your views here.
def gerenciar(request):
    personagens = [
        {
            "id": 1,
            "nome": "Carlinhos",
            "hp": 100,
            "ee": 80,
            "aparencia": 0
        },
        {
            "id": 2,
            "nome": "Jorgin",
            "hp": 50,
            "ee": 150,
            "aparencia": 13
        },
        {
            "id": 3,
            "nome": "Cleitin",
            "hp": 10,
            "ee": 200,
            "aparencia": 26
        },
        {
            "id": 4,
            "nome": "Fulano",
            "hp": 80,
            "ee": 20,
            "aparencia": 5
        },
    ]
    context = {'personagens': personagens}
    return render(request, 'gerenciar.html', context)

class PersonagensAPIView(APIView):

    def get(self, request, id):
        personagem = {
            "nome": "Carlinhos",
            "classe": 3,
            "aparencia": 0,
            "cabeca": 1,
            "corpo": 1,
            "pernas": 1,
            "hp": 10,
            "ee": 8,
            "ataque": 10,
            "defesa": 10,
            "sp_ataque": 10,
            "sp_defesa": 10,
            "velocidade": 10,
            "skill1": 1,
            "skill2": 1,
            "skill3": 2,
            "skill4": 2
        }
        return Response(personagem, status=status.HTTP_200_OK)

    def post(self, request):
        data = request.data
        dados_ordenados = [
            data['classe'],
            data['nome'],
            data['cabeca'],
            data['corpo'],
            data['pernas'],
            data['hp'],
            data['ee'],
            data['ataque'],
            data['defesa'],
            data['sp_ataque'],
            data['sp_defesa'],
            data['velocidade'],
            data['skill1'],
            data['skill2'],
            data['skill3'],
            data['skill4'],

        ]
    
        for i in range(len(dados_ordenados)):
            if dados_ordenados[i] == "":
                return Response({"erro":"Preencha todos os campos."}, status=status.HTTP_400_BAD_REQUEST)

        return Response({"sucesso":"Personagem criado com sucesso."}, status=status.HTTP_201_CREATED)
    
    def put(self, request, id):
        data = request.data
        dados_ordenados = [
            data['classe'],
            data['nome'],
            data['cabeca'],
            data['corpo'],
            data['pernas'],
            data['hp'],
            data['ee'],
            data['ataque'],
            data['defesa'],
            data['sp_ataque'],
            data['sp_defesa'],
            data['velocidade'],
            data['skill1'],
            data['skill2'],
            data['skill3'],
            data['skill4'],

        ]
    
        for i in range(len(dados_ordenados)):
            if dados_ordenados[i] == "":
                return Response({"erro":"Preencha todos os campos."}, status=status.HTTP_400_BAD_REQUEST)

        return Response({"sucesso":"Personagem editado com sucesso."}, status=status.HTTP_200_OK)
    
    def delete(self, request, id):
        return Response({"sucesso":"Personagem deletado com sucesso."}, status=status.HTTP_200_OK)