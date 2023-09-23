#include "Gerente.h"

int main(int argc, char *argv[]) {
  Gerente g;
    vector<Personagem> personagens = g.readPersonagens();

    for (Personagem p : personagens) {
        cout << p.id << ";" << p.classe << ";" << p.nome << ";" 
             << p.cabeca << ";" << p.corpo << ";" << p.pernas << ";"
             << p.hp << ";" << p.energia << ";" << p.ataque << ";" 
             << p.defesa << ";" << p.sp_ataque << ";" << p.sp_defesa << ";" 
             << p.velocidade << ";" << p.s1.id << ";" << p.s2.id << ";" 
             << p.s3.id << ";" << p.s4.id;
        cout << endl;
    }
}