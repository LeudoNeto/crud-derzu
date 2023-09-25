#pragma once
#include <string>
#include "Skill.h"
#include "Personagem.h"
#include <fstream>
#include "Gerente.h"
using namespace std;

class Berserker : public Personagem {
public:
    Berserker(int id, int classe, string nome, int cabeca, int corpo, int pernas, int hp, int energia, int ataque, int defesa, int sp_ataque, int sp_defesa, int velocidade, Skill s1, Skill s2, Skill s3, Skill s4)
        : Personagem(id, classe, nome, cabeca, corpo, pernas, hp, energia, ataque, defesa, sp_ataque, sp_defesa, velocidade, s1, s2, s3, s4) {}

    // Sobrescreva o método 'passive' na classe derivada
    void passiva() {
        ataque += 3;
        sp_ataque += 3;
    }

    Berserker() {}
};