#include "connecteur.h"
#include <QTextStream>

Connecteur::Connecteur(int pos, int dep, int arr):m_position(pos), m_depart(dep), m_arrivee(arr)
{

}

Connecteur::Connecteur(int dep, int arr):m_position(-1), m_depart(dep), m_arrivee(arr)
{

}

int Connecteur::getPosition() const
{
    return m_position;
}

int Connecteur::getDepart() const
{
    return m_depart;
}

int Connecteur::getArrivee() const
{
    return m_arrivee;
}

QString Connecteur::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << "Position=" << m_position << " ; de " << m_depart << " vers " << m_arrivee;
    return res;
}

bool Connecteur::lessPositionThan(Connecteur *c1, Connecteur *c2)
{
    return c1->getPosition() < c2->getPosition();
}

bool Connecteur::lessDepuisThan(Connecteur *c1, Connecteur *c2)
{
    return c1->getDepart() < c2->getDepart();
}

void Connecteur::setDepart(int depart)
{
    m_depart = depart;
}

void Connecteur::setArrivee(int arrivee)
{
    m_arrivee = arrivee;
}

void Connecteur::setPosition(int position)
{
    m_position = position;
}
