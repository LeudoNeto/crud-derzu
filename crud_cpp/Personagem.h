#pragma once
#include <string>
#include "Skill.h"
#include <fstream>
using namespace std;

class Personagem {
    public:
        int id, classe;
        string nome;
        int  cabeca, corpo, pernas;
        int hp, energia, ataque, defesa, sp_ataque, sp_defesa, velocidade;
        Skill s1, s2, s3, s4;

        Personagem(int id, int classe, string nome, int cabeca, int corpo, int pernas, int         hp, int energia, int ataque, int defesa, int sp_ataque, int sp_defesa, int                 velocidade, Skill s1, Skill s2, Skill s3, Skill s4)
        : id(id), classe(classe), nome(nome), cabeca(cabeca), corpo(corpo),                         pernas(pernas), hp(hp), energia(energia), ataque(ataque), defesa(defesa),                 sp_ataque(sp_ataque), sp_defesa(sp_defesa), velocidade(velocidade), s1(s1),                s2(s2), s3(s3), s4(s4) {}
        Personagem(){}
        
        void passiva() {};

        // Funções de escrita e leitura para serialização
        void write(ofstream& file) {
            file << id << ";" << classe << ";" << nome << ";" 
                 << cabeca << ";" << corpo << ";" << pernas << ";"
                 << hp << ";" << energia << ";" << ataque << ";" 
                 << defesa << ";" << sp_ataque << ";" << sp_defesa << ";"                          << velocidade << ";" << s1.id << ";" << s2.id << ";" 
                 << s3.id << ";" << s4.id;
            file << std::endl;
        }

        void read(std::ifstream& file) {
            char separator;
            file >> id >> separator >> classe >> separator;
            std::getline(file, nome, ';');
            file >> cabeca >> separator >> corpo >> separator >> pernas >> separator
                 >> hp >> separator >> energia >> separator >> ataque >> separator
                 >> defesa >> separator >> sp_ataque >> separator >> sp_defesa >> separator
                 >> velocidade >> separator >> s1.id >> separator >> s2.id >> separator
                 >> s3.id >> separator >> s4.id;
        
            // Lendo os atributos de Skill
            /*file >> separator;
            s1.read(file);
            file >> separator;
            s2.read(file);
            file >> separator;
            s3.read(file);
            file >> separator;
            s4.read(file);
        
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar caracteres              restantes na linha */
        }
};