#pragma once
#include <iostream>
#include "Skill.h"
#include "Personagem.h"
#include <vector>

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

        vector<Personagem> readPersonagens() {
            vector<Personagem> personagens;
            ifstream arquivo("personagens.txt");
            
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
                return personagens; // Retorna um vetor vazio em caso de erro
            }
            
            while (true) {
                Personagem p;
                if (!p.read(arquivo)) {
                    break; // Saia do loop se a leitura falhar
                }
                personagens.push_back(p);
            }
            
            arquivo.close();
            
            return personagens;
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

            // Verifique se o arquivo está vazio usando peek()
            if (arquivo.peek() == ifstream::traits_type::eof()) {
                arquivo.close();
                return 0; // Arquivo está vazio, retorne 0
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
          vector<Personagem> personagens = readPersonagens();
          
          for (const Personagem& p : personagens) {
              if (p.id == id) {
                  return p; // Retorna o personagem com o ID correspondente
              }
          }
          
          // Caso o ID não seja encontrado, você pode retornar um objeto Personagem vazio ou lançar uma exceção, dependendo dos requisitos do seu programa.
          cerr << "Personagem com ID " << id << " não encontrado." << endl;
          return Personagem(); // Retorna um objeto Personagem vazio (verifique se a classe Personagem possui um construtor padrão)
      }

  bool updatePersonagem(Personagem updatedPersonagem) {
    vector<Personagem> personagens = readPersonagens();
    
    for (Personagem& p : personagens) { // Use uma referência (&) aqui
        if (p.id == updatedPersonagem.id) {
            // Encontrou o personagem com o ID correspondente, atualize-o
            p = updatedPersonagem;
            
            // Reescreva todo o arquivo com os personagens atualizados
            ofstream arquivo("personagens.txt");
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
                return false; // Falha ao abrir o arquivo para escrita
            }
            
            for (const Personagem& personagem : personagens) {
                personagem.write(arquivo);
            }
            
            arquivo.close();
            
            return true; // Atualização bem-sucedida
        }
    }
    
    cerr << "Personagem com ID " << updatedPersonagem.id << " não encontrado." << endl;
    return false; // Personagem com o ID especificado não encontrado
  }

  bool deletePersonagem(int id) {
    vector<Personagem> personagens = readPersonagens();
    bool found = false; // Variável para rastrear se o personagem foi encontrado
    
    for (auto it = personagens.begin(); it != personagens.end(); ++it) {
        if (it->id == id) {
            // Encontrou o personagem com o ID correspondente, exclua-o
            it = personagens.erase(it);
            found = true;
            break; // Não é mais necessário continuar procurando
        }
    }
    
    if (!found) {
        cerr << "Personagem com ID " << id << " não encontrado." << endl;
        return false; // Personagem com o ID especificado não encontrado
    }
    
    // Reescreva todo o arquivo com os personagens restantes após a exclusão
    ofstream arquivo("personagens.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return false; // Falha ao abrir o arquivo para escrita
    }
    
    for (Personagem personagem : personagens) {
        personagem.write(arquivo);
    }
    
    arquivo.close();
    
    return true; // Exclusão bem-sucedida
  }

};
