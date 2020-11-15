#include "connecteur.h"
#include <QTextStream>

int Connecteur::getPosition() const
{
    return m_position;
}

int Connecteur::getDepuis() const
{
    return m_depuis;
}

int Connecteur::getVers() const
{
    return m_vers;
}

QString Connecteur::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << "Position=" << m_position << " ; de " << m_depuis << " vers " <<m_vers;
    return res;
}

bool Connecteur::lessPositionThan(Connecteur *c1, Connecteur *c2)
{
    return c1->getPosition() < c2->getPosition();
}

bool Connecteur::lessDepuisThan(Connecteur *c1, Connecteur *c2)
{
    return c1->getDepuis() < c2->getDepuis();
}

void Connecteur::setDepuis(int depuis)
{
    m_depuis = depuis;
}

void Connecteur::setVers(int vers)
{
    m_vers = vers;
}

Connecteur::Connecteur(int p, int d, int v):m_position(p), m_depuis(d), m_vers(v)
{

}

Connecteur::Connecteur(int d, int v):m_position(-1), m_depuis(d), m_vers(v)
{

}
