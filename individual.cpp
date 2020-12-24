#include "individual.h"
#include <QDebug>
#include <QTextStream>
#include "parameters.h"
#include "gene.h"
#include "reseaudetri.h"
#include <vector>

#include <iostream>
using namespace std;

static QString txt;

Individual::Individual()
{

}

Individual::Individual(Individual *father, Individual *mother)
{

}

double Individual::getFitness() const
{
    return m_fitness;
}


void Individual::setFitness(double fitness)
{
    m_fitness = fitness;
}

QString Individual::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<m_fitness<<" : {";
    foreach (Gene *rtg, genome) {
        Connecteur *c=rtg->getConnecteur();
        buf<<"["<<c->getDepart()<<","<<c->getArrivee()<<"] ";
    }
    buf<<"}";
    return res;
}

double Individual::evaluate()
{
    if(Parameters::individualsNb != 0)
    {
        for(int i = 1; i < Parameters::individualsNb + 1; i++)
        {
            double index1 = i;
        }
    }
}


void Individual::mutate()
{
    if(Parameters::randomGenerator->getFloat()<Parameters::mutationRate) {
        int index1 = Parameters::randomGenerator->get(genome.size());
        Gene *g = genome.at(index1);
        genome.removeAt(index1);
        int index2 = Parameters::randomGenerator->get(genome.size());
        genome.insert(index2, g);
    }
}

void Individual::run()
{
    ReseauDeTri::trieBulle();
}



