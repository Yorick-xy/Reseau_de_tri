#ifndef GENE_H
#define GENE_H

#include "connecteur.h"
#include <QString>

class Gene
{
private:
    Connecteur *m_connecteur;
    Connecteur *m_depart;
    Connecteur *m_arrivee;
public:
    Gene(Connecteur *connecteur);
    Gene(Gene &gene);
    Connecteur *getConnecteur() const;
    QString toString();
};

#endif // GENE_H
