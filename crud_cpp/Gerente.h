#pragma once
#include <iostream>
#include "Skill.h"
#include "Personagem.h"
#include<vector>

using namespace std;

class Gerente {
    public:
        Skill getSkillById(int id) {
            Skill skill;
            std::ifstream inFile("skills.txt");
        
            if (!inFile.is_open()) {
                std::cerr << "Erro ao abrir o arquivo." << std::endl;
                return skill; // Retorna uma Skill vazia em caso de erro
            }

            while (inFile.good()) {
                    skill.read(inFile); // Lê cada Skill do arquivo
                    if (skill.id == id) {
                        inFile.close(); // Fecha o arquivo
                        return skill; // Retorna a Skill encontrada
                    }
                }
            
                inFile.close(); // Fecha o arquivo
                skill.id = -1; // Define o ID como -1 para indicar que a Skill não foi encontrada
                return skill;
            }


        void create(Skill s) {
            ofstream arquivo("skills.txt", ios::binary | ios::app);
    
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
                return;
            }
            s.write(arquivo);
            arquivo.close();
        }
    
        void create(Personagem p) {
            int lastID = getLastPersonagemID();
            p.id = lastID + 1; // Incrementa o ID
            ofstream arquivo("personagens.txt", ios::app);
    
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
                return;
            }
    
            p.write(arquivo);
    
            arquivo.close();
        
    }

        int getLastPersonagemID() {
            ifstream arquivo("personagens.txt");
    
            if (!arquivo) {
                return 0; // Se o arquivo não existe, assume-se que o último ID é 0
            }
    
            Personagem p;
            int lastID = 0;
    
            while (!arquivo.eof()) {
                p.read(arquivo);
                lastID = p.id;
            }
    
            arquivo.close();
    
            return lastID;
        }

        vector<Skill> listSkills() {
          vector<Skill> skills;
          ifstream arquivo("skills.txt");

         if (!arquivo) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return skills;
          }

          Skill s;

          while (arquivo.good()) {
              s.read(arquivo);
              if (s.id != -1) { // Verifica se a Skill não foi marcada como não encontrada
                  skills.push_back(s);
              }
          }

          arquivo.close();

          return skills;
        }
        
};
