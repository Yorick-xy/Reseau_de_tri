#ifndef RESEAUDETRI_H
#define RESEAUDETRI_H

#include <QString>
#include <QList>
#include "connecteur.h"

class ReseauDeTri
{
private:
    int m_nbFil;
public:
    ReseauDeTri(int fil);
    int getNbFil() const;
    void setNbFil(int nbFil);
    void ajouteConnecteur(int pos, int dep, int arr);
    void ajouteConnecteur(Connecteur *connecteur);
    static void trieBulle();
    QString toString();

};

#endif // RESEAUDETRI_H
