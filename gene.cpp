#include "gene.h"
#include <QTextStream>

Connecteur *Gene::getConnecteur() const
{
    return m_connecteur;
}

QString Gene::toString()
{
    QString res;
    QTextStream buf(&res);

    buf << "Connecteur " << m_connecteur <<" : Depart = "<< m_depart << ", Arrivee = " << m_arrivee;

    return res;
}

Gene::Gene(Connecteur *connecteur):
    m_connecteur(connecteur)
{

}

Gene::Gene(Gene &gene):
    m_connecteur(gene.m_connecteur)
{

}
