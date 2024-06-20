#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include <fstream>
#include "lifeform.h"
#include <string>

class simulation {
int nb_alg,nbr_cor,nbr_scav;
public:
void lecture( std::ifstream& f);
    
};
#endif