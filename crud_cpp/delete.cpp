#include "Gerente.h"

int main(int argc, char *argv[]) {
  Gerente g;
  if (g.deletePersonagem(atoi(argv[1]))) {
    cout << 204 << endl;
  }
  else {
    cout << 500 << endl;
  }
}