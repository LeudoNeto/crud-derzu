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

      Personagem getPersonagemById(int id) {
        Personagem personagem; // Cria um objeto Personagem vazio
        // Abre o arquivo "personagens.txt" para leitura
        ifstream arquivo("personagens.txt");

        // Verifica se o arquivo foi aberto com sucesso
        if (!arquivo) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return personagem;
        }

        Personagem p; // Cria um objeto Personagem para ler os dados do arquivo

        // Inicia um loop para ler os registros do arquivo
        while (p.read(arquivo)) {
            // Verifica se o ID do personagem lido corresponde ao ID fornecido como argumento
            if (p.id == id) {
                // Fecha o arquivo após encontrar o personagem
                arquivo.close();
                // Retorna o personagem encontrado
                return p;
            }
        }

        // Fecha o arquivo após não encontrar o personagem
        arquivo.close();
        // Define o ID como -1 para indicar que o Personagem não foi encontrado
        personagem.id = -1;
        // Retorna o objeto Personagem vazio
        return personagem;
    }

  bool updatePersonagemById(int id, Personagem newPersonagem) {
        // Abre o arquivo "personagens.txt" para leitura
        ifstream inFile("personagens.txt");
        // Abre um arquivo temporário "temp.txt" para escrita
        ofstream outFile("temp.txt");

        // Verifica se os arquivos foram abertos com sucesso
        if (!inFile || !outFile) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return false;
        }

        Personagem p; // Cria um objeto Personagem para ler os dados do arquivo
        bool personagemEncontrado = false; // Flag para indicar se o personagem foi encontrado

        // Inicia um loop para ler os registros do arquivo
        while (p.read(inFile)) {
            // Verifica se o ID do personagem lido corresponde ao ID fornecido como argumento
            if (p.id == id) {
                // Escreve os novos dados do personagem no arquivo temporário
                outFile << newPersonagem.serialize() << endl;
                // Marca o personagem como encontrado
                personagemEncontrado = true;
            } else {
                // Escreve o personagem original no arquivo temporário
                outFile << p.serialize() << endl;
            }
        }

        // Fecha os arquivos após concluir as operações
        inFile.close();
        outFile.close();

        // Remove o arquivo original e renomeia o arquivo temporário para "personagens.txt"
        if (personagemEncontrado) {
            remove("personagens.txt");
            rename("temp.txt", "personagens.txt");
        } else {
            // Se o personagem não foi encontrado, apenas remova o arquivo temporário
            remove("temp.txt");
        }

        return personagemEncontrado;
    }

  bool removePersonagemById(int id) {
        // Abre o arquivo "personagens.txt" para leitura
        ifstream inFile("personagens.txt");
        // Abre um arquivo temporário "temp.txt" para escrita
        ofstream outFile("temp.txt");

        // Verifica se os arquivos foram abertos com sucesso
        if (!inFile || !outFile) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return false;
        }

        Personagem p; // Cria um objeto Personagem para ler os dados do arquivo
        bool personagemEncontrado = false; // Flag para indicar se o personagem foi encontrado

        // Inicia um loop para ler os registros do arquivo
        while (p.read(inFile)) {
            // Verifica se o ID do personagem lido corresponde ao ID fornecido como argumento
            if (p.id != id) {
                // Escreve o personagem original no arquivo temporário, exceto o que deve ser removido
                outFile << p.serialize() << endl;
            } else {
                // Marca o personagem como encontrado
                personagemEncontrado = true;
            }
        }

        // Fecha os arquivos após concluir as operações
        inFile.close();
        outFile.close();

        // Remove o arquivo original e renomeia o arquivo temporário para "personagens.txt"
        if (personagemEncontrado) {
            remove("personagens.txt");
            rename("temp.txt", "personagens.txt");
        } else {
            // Se o personagem não foi encontrado, apenas remova o arquivo temporário
            remove("temp.txt");
        }

        return personagemEncontrado;
    }

};
