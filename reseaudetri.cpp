#include "reseaudetri.h"
#include "connecteur.h"
#include "parameters.h"
#include "../shared/qstd.h"
#include <QTextStream>
#include <QDebug>

using namespace qstd;

ReseauDeTri::ReseauDeTri(int fil):m_nbFil(fil)
{

}

int ReseauDeTri::getNbFil() const
{
    return m_nbFil;
}

void ReseauDeTri::setNbFil(int nbFil)
{
    m_nbFil = nbFil;
}

QString ReseauDeTri::toString()
{

}


void ReseauDeTri::trieBulle()
{
    bool loop = true;
    while (loop) {
        loop = false;
        for(int i: Parameters::taille)
        {
                cout << "Le fil n : " << Parameters::taille[i] << " et le fil n+1 : " << Parameters::taille[i+1] << Qt::endl;
                if(Parameters::taille[i] > Parameters::taille[i+1])
                {
                    loop = true;
                    cout << "On inverse " << Parameters::taille[i] << " et le fil "<< Parameters::taille[i] << Qt::endl;
                    std::swap(Parameters::taille[i], Parameters::taille[i+1]);
                    cout << Qt::endl;
                    cout << "Nouvel ordre : ";
                    for(int l: Parameters::taille)
                    {
                        cout << Parameters::taille[l] << " ";
                    }
                    cout << Qt::endl;
                }
                else
                {
                    cout << Qt::endl;
                    cout<<"Les elements sont bien tries."<<Qt::endl;
                    cout << "Ordre final : ";
                    for(int k: Parameters::taille)
                    {
                        cout << Parameters::taille[k] << " ";
                    }
                }
        }
    }//fin du while
}
