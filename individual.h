#ifndef RESTRIINDIVIDUAL_H
#define RESTRIINDIVIDUAL_H

#include <QList>
#include "gene.h"
#include "evolutionaryprocess.h"

class Individual
{
private:
    double m_fitness =- 1;
public:
    QList<Gene *> genome;
    Individual();
    Individual(Individual *father);
    Individual(Individual *father, Individual *mother);
    double getFitness() const;
    void setFitness(double fitness);
    void mutate();
    void selection();
    void run();
    double evaluate();
    QString toString();
    static bool lessFitnessThan(const Individual *rti1, const Individual *rti2);
};

#endif // RESTRIINDIVIDUAL_H
