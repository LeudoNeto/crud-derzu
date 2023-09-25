#pragma once
#include <string>
#include "Skill.h"
#include "Personagem.h"
#include <fstream>
#include "Gerente.h"
#include <random>
using namespace std;

class Ocilante : public Personagem {
public:
    Ocilante(int id, int classe, string nome, int cabeca, int corpo, int pernas, int hp, int energia, int ataque, int defesa, int sp_ataque, int sp_defesa, int velocidade, Skill s1, Skill s2, Skill s3, Skill s4)
        : Personagem(id, classe, nome, cabeca, corpo, pernas, hp, energia, ataque, defesa, sp_ataque, sp_defesa, velocidade, s1, s2, s3, s4) {}

    // Sobrescreva o método 'passive' na classe derivada
    void passiva() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1); // Gera números 0 ou 1 (true ou false)

        bool randomBool = dis(gen); 
        if(randomBool)
        {
            hp *= 1.15;
            energia *= 1.15;
            ataque *= 1.15;
            defesa *= 1.15;
            sp_ataque *= 1.15;
            sp_defesa *= 1.15;
            velocidade *= 1.15;
        }
        else
        {
            hp *= 0.9;
            energia *= 0.9;
            ataque *= 0.9;
            defesa *= 0.9;
            sp_ataque *= 0.9;
            sp_defesa *= 0.9;
            velocidade *= 0.9;
        }
    }

    Ocilante() {}
};