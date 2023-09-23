#include "Assassino.h"
#include "Berserker.h"
#include "Ocilante.h"
#include "Paladino.h"
#include "Regenerador.h"
#include "Velocista.h"

#include "Gerente.h"

using namespace std;

int main(int argc, char *argv[]) {
  Gerente g;
  if (atoi(argv[2]) == 0) {
    Berserker b(atoi(argv[1]), atoi(argv[2]), argv[3],
               atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
               atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
               atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
               atoi(argv[13]), g.getSkillById(atoi(argv[14])),
               g.getSkillById(atoi(argv[15])), g.getSkillById(atoi(argv[16])),
               g.getSkillById(atoi(argv[17])));
    b.passiva(argv[18]);
    cout << b.hp << ";" << b.energia << ";" << b.ataque << ";" 
         << b.defesa << ";" << b.sp_ataque << ";" << b.sp_defesa << ";" 
         << b.velocidade << endl;
  }
}