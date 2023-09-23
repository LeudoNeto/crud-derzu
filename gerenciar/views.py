from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
import subprocess

# Create your views here.
def gerenciar(request):
    completed_process = subprocess.run("./crud_cpp/read", stdout=subprocess.PIPE, text=True, shell=True)
    output = completed_process.stdout

    personagens = []
    linhas = output.split('\n')[:-1]

    # Itere pelas linhas e crie um dicionário para cada personagem
    for linha in linhas:
        campos = linha.split(';')
        personagem = {
            "id": int(campos[0]),
            "nome": campos[2],
            "hp": int(campos[6])*10,
            "ee": int(campos[7]),
            "aparencia": (int(campos[3])-1)*9 + (int(campos[4])-1)*3 + (int(campos[5])-1)
        }
        personagens.append(personagem)

    context = {'personagens': personagens}
    return render(request, 'gerenciar.html', context)

class PersonagensAPIView(APIView):

    def get(self, request, id):
        completed_process = subprocess.run(f"./crud_cpp/readById {id}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout

        campos = output.split(';')
        personagem = {
            "id": int(campos[0]),
            "classe": campos[1],
            "nome": campos[2],
            "aparencia": (int(campos[3])-1)*9 + (int(campos[4])-1)*3 + (int(campos[5])-1),
            "cabeca": int(campos[3]),
            "corpo": int(campos[4]),
            "pernas": int(campos[5]),
            "hp": int(campos[6]),
            "ee": int(campos[7]),
            "ataque": int(campos[8]),
            "defesa": int(campos[9]),
            "sp_ataque": int(campos[10]),
            "sp_defesa": int(campos[11]),
            "velocidade": int(campos[12]),
            "skill1": campos[13],
            "skill2": campos[14],
            "skill3": campos[15],
            "skill4": campos[16][:-1],
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

        completed_process = subprocess.run(f"./crud_cpp/create {' '.join(dados_ordenados)}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout
        
        if '200' in output:
            return Response({"sucesso":"Personagem criado com sucesso."}, status=status.HTTP_201_CREATED)
        else:
            return Response({"erro":"Ocorreu um erro na comunicação com o banco de dados."}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
    
    def put(self, request, id):
        data = request.data
        dados_ordenados = [
            str(id),
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
            
        completed_process = subprocess.run(f"./crud_cpp/update {' '.join(dados_ordenados)}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout
        
        if '200' in output:
            return Response({"sucesso":"Personagem criado com sucesso."}, status=status.HTTP_201_CREATED)
        else:
            return Response({"erro":"Ocorreu um erro na comunicação com o banco de dados."}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
    
    def delete(self, request, id):
        completed_process = subprocess.run(f"./crud_cpp/delete {id}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout

        if '204' in output:
            return Response({"sucesso":"Personagem deletado com sucesso."}, status=status.HTTP_200_OK)
        else:
            return Response({"erro":"Ocorreu um erro na comunicação com o banco de dados."}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)