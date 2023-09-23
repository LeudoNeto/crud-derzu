#include <iostream>
#include <string>
#include "Skill.h"
#include "Gerente.h"

using namespace std;

// g++ createSkill.cpp -o createSkill && ./createSkill 1 Investida -5 2 0 0 1 0 0 0 1

int main(int argc, char *argv[])
{
    Gerente g;
    float multiplicadores[7] = {stof(argv[5]), stof(argv[6]), stof(argv[7]), stof(argv[8]), stof(argv[9]), stof(argv[10]), stof(argv[11])};
    Skill s(atoi(argv[1]), argv[2], atoi(argv[3]), atoi(argv[4]), multiplicadores);

    g.create(s);

    vector<Skill> skills = g.listSkills();

    if (skills.empty()) {
        cout << "Nenhuma Skill encontrada." << endl;
    } else {
        cout << "Skills criadas:" << endl;
        for (const Skill& skill : skills) {
            skill.printInfo(); // Imprime informações de cada Skill
            cout << endl;
        }
    }

    return 0;
}