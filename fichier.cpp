#include "simulation.h"
#include "simulation.cc"
#include <iostream>
#include <fstream>
#include <string>
#include "message.h"
#include "lifeform.h"
#include "simulation.h"
#include "shape.h"
#include "message.cc"
#include "lifeform.cc"
#include "shape.cc"
int main()
{
    ifstream fichier("t00.txt");
    simulation s;
    s.lecture(fichier);
    return 0;
}