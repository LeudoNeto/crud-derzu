from django.shortcuts import render
import json
from django.http import JsonResponse

# Create your views here.
def escolher_personagens(request):
    personagens = [
        {
            'id': 1,
            'nome': 'Cleitin',
            'cabeca': 1,
            'hp': 10,
            'ee': 10,
            'ataque': 10,
            'defesa': 10,
            'sp_ataque': 10,
            'sp_defesa': 10,
            'velocidade': 10
        },
        {
            'id': 1,
            'nome': 'Jorgin',
            'cabeca': 2,
            'hp': 20,
            'ee': 5,
            'ataque': 8,
            'defesa': 4,
            'sp_ataque': 5,
            'sp_defesa': 2,
            'velocidade': 20
        },
        {
            'id': 1,
            'nome': 'Carlinhos',
            'cabeca': 3,
            'hp': 10,
            'ee': 20,
            'ataque': 30,
            'defesa': 5,
            'sp_ataque': 1,
            'sp_defesa': 20,
            'velocidade': 1
        },
        {
            'id': 1,
            'nome': 'Giorno Giovanna',
            'cabeca': 1,
            'hp': 100,
            'ee': 100,
            'ataque': 100,
            'defesa': 100,
            'sp_ataque': 100,
            'sp_defesa': 100,
            'velocidade': 100
        },
    ]
    context = {
        'personagens': personagens
    }
    return render(request, 'escolher_personagens.html', context)

def partida(request, id_1, id_2):
    personagem_1 = {
        'id': 1,
        'nome': 'Cleitin',
        'cabeca': 1,
        'aparencia': 0,
        'hp': 100,
        'ee': 10,
        'ataque': 10,
        'defesa': 10,
        'sp_ataque': 10,
        'sp_defesa': 10,
        'velocidade': 100,
        's1_id': 1,
        's1_nome': 'Investida',
        's2_id': 2,
        's2_nome': 'golpe de escudo',
        's3_id': 3,
        's3_nome': 'golpe pesado',
        's4_id': 4,
        's4_nome': 'golpe poderoso'
    }
    personagem_2 = {
        'id': 1,
        'nome': 'Jorgin',
        'cabeca': 2,
        'aparencia': 9,
        'hp': 200,
        'ee': 5,
        'ataque': 8,
        'defesa': 4,
        'sp_ataque': 5,
        'sp_defesa': 2,
        'velocidade': 20,
        's1_id': 5,
        's1_nome': 'kickbox',
        's2_id': 6,
        's2_nome': 'bola de fogo',
        's3_id': 7,
        's3_nome': 'raio',
        's4_id': 8,
        's4_nome': 'flecha de gelo'
    }

    context = {
        'personagem_1': personagem_1,
        'personagem_2': personagem_2
    }
    return render(request, 'partida.html', context)

def calcular_dano(request):
    data = json.loads(request.body)
    id = data.get('id')
    return JsonResponse({'dano': 50})

def passiva(request):
    data = json.loads(request.body)
    hp = data.get('hp')
    ee = data.get('ee')
    ataque = data.get('ataque')
    defesa = data.get('defesa')
    sp_ataque = data.get('sp_ataque')
    sp_defesa = data.get('sp_defesa')
    velocidade = data.get('velocidade')

    novos_atributos = {
        'hp': int(hp)+2,
        'ee': int(ee)+10,
        'ataque': int(ataque)+3,
        'defesa': int(defesa)+5,
        'sp_ataque': sp_ataque,
        'sp_defesa': sp_defesa,
        'velocidade': velocidade
    }
    return JsonResponse(novos_atributos)