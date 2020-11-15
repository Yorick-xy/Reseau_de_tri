#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "myrandom.h"
#include <QString>

class Parameters {
public:
    static int individualsNb;
    static int generationsMaxNb;
    static int initialGenesNb;
    static int minFitness;

    static double mutationRate;
    static double mutationAddRate;
    static double mutationDeleteRate;
    static double crossoverRate;

    static MyRandom *randomGenerator;

    static int debug;
    static void print(QString txt, int d);

    // réseau de tri
    static int nbFils;
    static int taille[17];
    // historiques
};

#endif // PARAMETERS_H
