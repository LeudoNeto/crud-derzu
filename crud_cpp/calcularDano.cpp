#include "Skill.h"
#include "Gerente.h"

void Skill::calcularDano(int hp, int pw, int atk, int def, int m_atk, 
int m_def, int spd, int def_en, int m_def_en) {

    float dano_verdadeiro = (dano_base 
        + hp*multiplicadores_atributos[0] 
        + atk*multiplicadores_atributos[1] 
        + def*multiplicadores_atributos[2]           +     
        + m_atk*multiplicadores_atributos[3] 
        + m_def*multiplicadores_atributos[4]
        + spd*multiplicadores_atributos[5] 
        + pw*multiplicadores_atributos[6]);
  
    printf("%.0f",(tipo == 'm') ?       
      dano_verdadeiro - ((dano_verdadeiro) * (m_def_en/(m_def_en + 20.0)))       : 
      dano_verdadeiro - ((dano_verdadeiro) * (def_en/(def_en + 20.0))));
            
}

int main(int argc, char *argv[]) {
    Gerente g;
    Skill skl = g.getSkillById(atoi(argv[1]));

    skl.calcular_dano(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]));
}