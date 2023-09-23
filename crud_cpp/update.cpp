#include "Gerente.h"

int main(int argc, char *argv[]) {
  Gerente g;
  Personagem p(atoi(argv[1]), atoi(argv[2]), argv[3],
               atoi(argv[4]), atoi(argv[5]), atoi(argv[6]),
               atoi(argv[7]), atoi(argv[8]), atoi(argv[9]),
               atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
               atoi(argv[13]), g.getSkillById(atoi(argv[14])),
               g.getSkillById(atoi(argv[15])), g.getSkillById(atoi(argv[16])),
               g.getSkillById(atoi(argv[17])));
  if (g.updatePersonagem(p)) {
    cout << 200 << endl;
  }
  else {
    cout << 500 << endl;
  }
}