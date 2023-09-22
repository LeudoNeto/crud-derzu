#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Skill {
    public:
        int id;
        string nome;
        int custo;
        int dano_base;
        float multiplicador_base;
        float multiplicadores_atributos[7];
    
        Skill() {}

        Skill(int id, string nome, int custo, int dano_base, float multiplicador_base, float multiplicadores_atributos[7])
        : id(id), nome(nome), custo(custo), dano_base(dano_base), multiplicador_base(multiplicador_base) {
            for (int i = 0; i < 7; i++) {
                this->multiplicadores_atributos[i] = multiplicadores_atributos[i];
            }
        }
    
        void calcular_dano() {
    
        }
};

class Personagem {
    public:
        int id, classe;
        string nome;
        int  cabeca, corpo, pernas;
        int hp, energia, ataque, defesa, sp_ataque, sp_defesa, velocidade;
        Skill s1, s2, s3, s4;

        Personagem(int id, int classe, string nome, int cabeca, int corpo, int pernas, int hp, int energia, int ataque, int defesa, int sp_ataque, int sp_defesa, int velocidade, Skill s1, Skill s2, Skill s3, Skill s4)
        : id(id), classe(classe), nome(nome), cabeca(cabeca), corpo(corpo), pernas(pernas), hp(hp), energia(energia), ataque(ataque), defesa(defesa), sp_ataque(sp_ataque), sp_defesa(sp_defesa), velocidade(velocidade), s1(s1), s2(s2), s3(s3), s4(s4) {}
        void passiva() {};
};

class Berserker : public Personagem {
    public:
        void passiva() {
            ataque += 2;
            velocidade += 2;
            defesa -= 4;
        }
};

class Gerente {
    public:
        Skill getSkillById(int id) {
            ifstream arquivo("skills.bin", ios::binary);
            Skill s;
        
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
            }

            while (arquivo.read(reinterpret_cast<char*>(&s), sizeof(Skill))) {
                if (s.id == id) {
                    arquivo.close();
                    cout << "pegou" << endl;
                    return s;
                }
            }
            
        
            arquivo.close();
            
            return s;
        } 

        void create(Skill s) {
            ofstream arquivo("skills.bin", ios::binary | ios::app);
        
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
            }
        
            arquivo.write(reinterpret_cast<char*>(&s), sizeof(Skill));
        
            arquivo.close();
        }
    
        void create(Personagem *p) {
            ofstream arquivo("personagens.bin", ios::binary | ios::app);
            
            if (!arquivo) {
                cerr << "Erro ao abrir o arquivo." << endl;
            }
            
            arquivo.write(reinterpret_cast<char*>(p), sizeof(Personagem));
        
            arquivo.close();
        }
};

int main(int argc, char *argv[])
{
    Gerente g;
    float multiplicadores[7] = {stof(argv[6]), stof(argv[7]), stof(argv[8]), stof(argv[9]), stof(argv[10]), stof(argv[11]), stof(argv[12])};
    Skill s(atoi(argv[1]), argv[2], atoi(argv[3]), atoi(argv[4]), stof(argv[5]), multiplicadores);

    g.create(s);

    return 0;
}