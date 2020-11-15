#ifndef RESEAUDETRI_H
#define RESEAUDETRI_H

#include "connecteur.h"
#include <QList>

class ReseauDeTri : public QList<Connecteur *>
{
private:
    int m_nbFils;
    QList<int> m_valDep, m_valFin;
public:
    ReseauDeTri(int nb);
    void ajouteConnecteur(int p, int d, int v);
    void ajouteConnecteur(int d, int v);
    void ajouteConnecteur(Connecteur *c);
    QString toString();
    int getPosMax();
    ReseauDeTri getConnecteurs(int pos);
    QList<int> injecte(QList<int> &valeurs);
    bool testZeroUn();
    int testZeroUnVal();
    void parallele();
    int getNbFils() const;
    QList<int> getValDep() const;
    QList<int> getValFin() const;
};

#endif // RESEAUDETRI_H
