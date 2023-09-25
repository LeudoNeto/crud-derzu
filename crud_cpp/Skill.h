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
        void calcular_dano(int hp, int pw, int atk, int def, int m_atk, int m_def, int spd, int def_en, int m_def_en);

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
    
        bool read(std::ifstream& file) {
            char separator;
            if (!(file >> id >> separator)) {
                return false; // Falha na leitura de id e separador
            }
            std::getline(file, nome, ';');
            if (!(file >> tipo >> separator)) {
                return false; // Falha na leitura de tipo e separador
            }
            if (!(file >> custo >> separator)) {
                return false; // Falha na leitura de custo e separador
            }
            if (!(file >> dano_base >> separator)) {
                return false; // Falha na leitura de dano_base e separador
            }
            for (int i = 0; i < 7; i++) {
                if (!(file >> multiplicadores_atributos[i])) {
                    return false; // Falha na leitura dos multiplicadores
                }
                if (i < 6 && !(file >> separator)) {
                    return false; // Falha na leitura dos separadores
                }
            }
            return true; // Leitura bem-sucedida
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