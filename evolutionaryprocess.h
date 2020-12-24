#ifndef EVOLUTIONARYPROCESS_H
#define EVOLUTIONARYPROCESS_H
#include "gene.h"
#include <QString>

class EvolutionaryProcess
{
private:
    int m_generationNb;
    int m_population;
public:
    EvolutionaryProcess();
    EvolutionaryProcess(int nb);
    int getPopulation() const;
    int getGenerationNb() const;
    int selection();
    int survival();
    void run();
    QString toString();

};

#endif // EVOLUTIONARYPROCESS_H
