#include "Skill.h"

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
  
    printf("%.0f",(id > 5) ?       
      (dano_verdadeiro) * (10.0/(m_def_en + 10.0)) : 
      (dano_verdadeiro) * (10.0/(def_en + 10.0)));
            
}