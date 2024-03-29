#include "parameters.h"
#include "../shared/qstd.h"
using namespace qstd;

int Parameters::individualsNb = 20;
int Parameters::generationsMaxNb = 20;
int Parameters::initialGenesNb = 0;
int Parameters::minFitness = 0;

double Parameters::mutationRate = 0.5;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;
double Parameters::indiceQualite[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};

int Parameters::taille[17]={
    0, 10, 1, 3, 5, 9, 12, 16, 19, 25, 29, 35, 39, 45, 51, 56, 60
};
int Parameters::nbFils = 6;


// TODO : modifier la graine : mettre 0 pour constant, enlever sinon.
MyRandom *Parameters::randomGenerator = new MyRandom();

int Parameters::debug = 0;

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<Qt::endl;
}
