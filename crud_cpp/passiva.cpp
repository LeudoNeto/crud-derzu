#include "Assassino.h"
#include "Berserker.h"
#include "Oscilante.h"
#include "Paladino.h"
#include "Regenerador.h"
#include "Velocista.h"

#include "Gerente.h"

using namespace std;

// g++ passiva.cpp -o passiva && ./passiva 1 3 Carlinhos 1 3 1 10 10 10 10 10 10 10 2 5 6 10 0 6

int main(int argc, char *argv[]) {
  Gerente g;
  int classe = atoi(argv[2]);
  if (classe == 0){
      Assassino a(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      a.passiva();
      cout << a.hp << ";" << a.energia << ";" << a.ataque << ";" 
           << a.defesa << ";" << a.sp_ataque << ";" << a.sp_defesa << ";" 
           << a.velocidade << endl;
  
  }
  if(classe == 1){
      Berserker b(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),         g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      b.passiva();
      cout << b.hp << ";" << b.energia << ";" << b.ataque << ";" 
           << b.defesa << ";" << b.sp_ataque << ";" << b.sp_defesa << ";" 
           << b.velocidade << endl;
  
  }
  if(classe == 2){
      Ocilante o(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),         g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      o.passiva();
      cout << o.hp << ";" << o.energia << ";" << o.ataque << ";" 
           << o.defesa << ";" << o.sp_ataque << ";" << o.sp_defesa << ";" 
           << o.velocidade << endl;
  
  }
  if(classe == 3){
      Paladino p(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),         g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      p.passiva();
      cout << p.hp << ";" << p.energia << ";" << p.ataque << ";" 
           << p.defesa << ";" << p.sp_ataque << ";" << p.sp_defesa << ";" 
           << p.velocidade << endl;
  
  }
  if(classe == 4){
      Regenerador r(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),         g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      r.passiva();
      cout << r.hp << ";" << r.energia << ";" << r.ataque << ";" 
           << r.defesa << ";" << r.sp_ataque << ";" << r.sp_defesa << ";" 
           << r.velocidade << endl;
  
  }
  if(classe == 5){
      Velocista v(atoi(argv[1]), atoi(argv[2]), argv[3],
                 atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
                 atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
                 atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                 atoi(argv[13]), g.getSkillById(atoi(argv[14])),
                 g.getSkillById(atoi(argv[15])),         g.getSkillById(atoi(argv[16])),
                 g.getSkillById(atoi(argv[17])));
      v.passiva();
      cout << v.hp << ";" << v.energia << ";" << v.ataque << ";" 
           << v.defesa << ";" << v.sp_ataque << ";" << v.sp_defesa << ";" 
           << v.velocidade << endl;
  
  }
    
}