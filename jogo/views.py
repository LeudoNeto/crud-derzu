from django.shortcuts import render
import json
from django.http import JsonResponse
import subprocess
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

# Create your views here.
def escolher_personagens(request):
    completed_process = subprocess.run("./crud_cpp/read", stdout=subprocess.PIPE, text=True, shell=True)
    output = completed_process.stdout

    personagens = []
    linhas = output.split('\n')[:-1]

    # Itere pelas linhas e crie um dicionário para cada personagem
    for linha in linhas:
        campos = linha.split(';')
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
        "skill4": campos[16],
        }

        personagens.append(personagem)

    context = {
        'personagens': personagens
    }
    return render(request, 'escolher_personagens.html', context)

def partida(request, id_1, id_2):

    skills = ['Investida', 'golpe de escudo', 'golpe pesado', 
                  'golpe poderoso', 'kickbox', 'bola de fogo', 
                  'raio', 'flecha de gelo', 'bala magica', 
                  'raio de vitalidade', 'golpe de vitalidade', 
                  'bolha bomba']

    completed_process = subprocess.run(f"./crud_cpp/readById {id_1}", stdout=subprocess.PIPE, text=True, shell=True)
    output = completed_process.stdout

    campos = output.split(';')
    personagem_1 = {
        "id": int(campos[0]),
        "classe": campos[1],
        "nome": campos[2],
        "aparencia": (int(campos[3])-1)*9 + (int(campos[4])-1)*3 + (int(campos[5])-1),
        "cabeca": int(campos[3]),
        "corpo": int(campos[4]),
        "pernas": int(campos[5]),
        "hp": int(campos[6])*10,
        "ee": int(campos[7]),
        "ataque": int(campos[8]),
        "defesa": int(campos[9]),
        "sp_ataque": int(campos[10]),
        "sp_defesa": int(campos[11]),
        "velocidade": int(campos[12]),
        "s1_id": campos[13],
        "s1_nome": skills[int(campos[13])-1],
        "s2_id": campos[14],
        "s2_nome": skills[int(campos[14])-1],
        "s3_id": campos[15],
        "s3_nome": skills[int(campos[15])-1],
        "s4_id": campos[16][:-1],
        "s4_nome": skills[int(campos[16][:-1])-1]
    }

    completed_process = subprocess.run(f"./crud_cpp/readById {id_2}", stdout=subprocess.PIPE, text=True, shell=True)
    output = completed_process.stdout

    campos = output.split(';')
    personagem_2 = {
        "id": int(campos[0]),
        "classe": campos[1],
        "nome": campos[2],
        "aparencia": (int(campos[3])-1)*9 + (int(campos[4])-1)*3 + (int(campos[5])-1),
        "cabeca": int(campos[3]),
        "corpo": int(campos[4]),
        "pernas": int(campos[5]),
        "hp": int(campos[6])*10,
        "ee": int(campos[7]),
        "ataque": int(campos[8]),
        "defesa": int(campos[9]),
        "sp_ataque": int(campos[10]),
        "sp_defesa": int(campos[11]),
        "velocidade": int(campos[12]),
        "s1_id": campos[13],
        "s1_nome": skills[int(campos[13])-1],
        "s2_id": campos[14],
        "s2_nome": skills[int(campos[14])-1],
        "s3_id": campos[15],
        "s3_nome": skills[int(campos[15])-1],
        "s4_id": campos[16][:-1],
        "s4_nome": skills[int(campos[16][:-1])-1]
    }

    context = {
        'personagem_1': personagem_1,
        'personagem_2': personagem_2
    }
    return render(request, 'partida.html', context)

class calcular_dano(APIView):

    def post(self, request):
        id = request.data.get('id')
        hp = request.data.get('hp')
        ee = request.data.get('ee')
        ataque = request.data.get('ataque')
        defesa = request.data.get('defesa')
        sp_ataque = request.data.get('sp_ataque')
        sp_defesa = request.data.get('sp_defesa')
        velocidade = request.data.get('velocidade')
        alvo_defesa = request.data.get('alvo_defesa')
        alvo_sp_defesa = request.data.get('alvo_sp_defesa')

        dados_ordenados = [id, hp, ee, ataque, defesa, sp_ataque, 
                             sp_defesa, velocidade, alvo_defesa, alvo_sp_defesa]

        completed_process = subprocess.run(f"./crud_cpp/calcularDano {' '.join(dados_ordenados)}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout

        return Response({'dano': output}, status=status.HTTP_200_OK)

class passiva(APIView):

    def post(self, request):
        data = request.data
        classe = data.get('classe')
        hp = data.get('hp')
        ee = data.get('ee')
        ataque = data.get('ataque')
        defesa = data.get('defesa')
        sp_ataque = data.get('sp_ataque')
        sp_defesa = data.get('sp_defesa')
        velocidade = data.get('velocidade')

        dados_ordenados = ['1', classe, 'nome', '1', '1', '1', hp, ee, ataque,
                           defesa, sp_ataque, sp_defesa, velocidade, '1', '1', '1', '1']

        completed_process = subprocess.run(f"./crud_cpp/passiva {' '.join(dados_ordenados)}", stdout=subprocess.PIPE, text=True, shell=True)
        output = completed_process.stdout
        campos = output.split(';')

        hp = campos[0]
        ee = campos[1]
        ataque = campos[2]
        defesa = campos[3]
        sp_ataque = campos[4]
        sp_defesa = campos[5]
        velocidade = campos[6][:-1]

        novos_atributos = {
            'hp': hp,
            'ee': ee,
            'ataque': ataque,
            'defesa': defesa,
            'sp_ataque': sp_ataque,
            'sp_defesa': sp_defesa,
            'velocidade': velocidade
        }
        return Response(novos_atributos, status=status.HTTP_200_OK)