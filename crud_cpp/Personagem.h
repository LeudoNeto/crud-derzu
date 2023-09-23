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
        : id(id), classe(classe), nome(nome), cabeca(cabeca), corpo(corpo),                         pernas(pernas), hp(hp), energia(energia), ataque(ataque), defesa(defesa),                 sp_ataque(sp_ataque), sp_defesa(sp_defesa), velocidade(velocidade), s1(s1), s2(s2), s3(s3), s4(s4) {}
        Personagem(){}

        // Funções de escrita e leitura para serialização
        void write(ofstream& file) const {
            file << id << ";" << classe << ";" << nome << ";" 
                 << cabeca << ";" << corpo << ";" << pernas << ";"
                 << hp << ";" << energia << ";" << ataque << ";" 
                 << defesa << ";" << sp_ataque << ";" << sp_defesa << ";"                          << velocidade << ";" << s1.id << ";" << s2.id << ";" 
                 << s3.id << ";" << s4.id;
            file << std::endl;
        }

        bool read(std::ifstream& file) {
            char separator;
            if (!(file >> id >> separator >> classe >> separator)) {
                return false; // Erro na leitura dos campos iniciais
            }
            
            std::getline(file, nome, ';');
            
            if (!(file >> cabeca >> separator >> corpo >> separator >> pernas >> separator
                 >> hp >> separator >> energia >> separator >> ataque >> separator
                 >> defesa >> separator >> sp_ataque >> separator >> sp_defesa >> separator
                 >> velocidade >> separator >> s1.id >> separator >> s2.id >> separator
                 >> s3.id >> separator >> s4.id)) {
                return false; // Erro na leitura dos campos restantes
            }
            
            return true; // Leitura bem-sucedida
        }

        void printInfo() const {
            cout << "ID: " << id << endl;
            cout << "Classe: " << classe << endl;
            cout << "Nome: " << nome << endl;
            cout << "Cabeca: " << cabeca << endl;
            cout << "Corpo: " << corpo << endl;
            cout << "Pernas: " << pernas << endl;
            cout << "HP: " << hp << endl;
            cout << "Energia: " << energia << endl;
            cout << "Ataque: " << ataque << endl;
            cout << "Defesa: " << defesa << endl;
            cout << "Special Attack: " << sp_ataque << endl;
            cout << "Special Defense: " << sp_defesa << endl;
            cout << "Velocidade: " << velocidade << endl;
        
            cout << "Skills:" << endl;
            cout << "Skill 1: ";
            s1.printInfo();
            cout << "Skill 2: ";
            s2.printInfo();
            cout << "Skill 3: ";
            s3.printInfo();
            cout << "Skill 4: ";
            s4.printInfo();
        }
      
};