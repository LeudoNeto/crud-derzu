#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Skill {
    public:
        int id;
        string nome;
        char tipo; // m para mágico/f para físico
        int custo;
        int dano_base;
        float multiplicadores_atributos[7];
    
        Skill() {}

        Skill(int id, string nome, char tipo, int custo, int dano_base, float multiplicadores_atributos[7])
        : id(id), nome(nome), tipo(tipo), custo(custo), dano_base(dano_base) {
            for (int i = 0; i < 7; i++) {
                this->multiplicadores_atributos[i] = multiplicadores_atributos[i];
            }
        }
        void calcular_dano();

        // Funções de escrita e leitura para serialização
        void write(std::ofstream& file) {
            file << id << ";" << nome << ";" << custo << ";" << dano_base << ";";
            for (int i = 0; i < 7; i++) {
                file << multiplicadores_atributos[i];
                if (i < 6) {
                    file << ";"; // Separador ponto e vírgula
                }
            }
            file << std::endl;
        }
    
        void read(std::ifstream& file) {
            char separator;
            file >> id >> separator;
            std::getline(file, nome, ';');
            file >> tipo >> separator;
            file >> custo >> separator;
            file >> dano_base >> separator;
            for (int i = 0; i < 7; i++) {
                file >> multiplicadores_atributos[i];
                if (i < 6) {
                    file >> separator;
                }
            }
        }


        void printInfo() const {
            cout << "ID: " << id << endl;
            cout << "Nome: " << nome << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Custo: " << custo << endl;
            cout << "Dano Base: " << dano_base << endl;
            cout << "Multiplicadores de Atributos: ";
            for (int i = 0; i < 7; i++) {
                cout << multiplicadores_atributos[i] << " ";
            }
            cout << endl;
        }
};