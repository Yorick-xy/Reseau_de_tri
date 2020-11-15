#include "reseaudetri.h"
#include <QTextStream>
#include <QDebug>
#include "misc.h"

int ReseauDeTri::getNbFils() const
{
    return m_nbFils;
}


QList<int> ReseauDeTri::getValDep() const
{
    return m_valDep;
}

QList<int> ReseauDeTri::getValFin() const
{
    return m_valFin;
}

ReseauDeTri::ReseauDeTri(int nb):m_nbFils(nb)
{

}

void ReseauDeTri::ajouteConnecteur(int p, int d, int v)
{
    this->append(new Connecteur(p, d, v));
}

void ReseauDeTri::ajouteConnecteur(int d, int v)
{
    this->append(new Connecteur(getPosMax()+1, d, v));
}

void ReseauDeTri::ajouteConnecteur(Connecteur *c)
{
    this->append(c);
}

QString ReseauDeTri::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Ce reseau contient "<<m_nbFils<<" fils et "<<this->size()<<" connecteurs :";
    foreach (Connecteur *c, *this) {
        buf<<Qt::endl<<"- "<<c->toString();
    }
    return res;
}

int ReseauDeTri::getPosMax()
{
    int res=-1;
    foreach (Connecteur *c, *this) {
        if(res<c->getPosition())
            res=c->getPosition();
    }
    return res;
}

ReseauDeTri ReseauDeTri::getConnecteurs(int pos)
{
    ReseauDeTri res(m_nbFils);
    foreach (Connecteur *c, *this) {
        if(c->getPosition()==pos)
            res.ajouteConnecteur(c);
    }
    return res;
}

QList<int> ReseauDeTri::injecte(QList<int> &valeurs)
{
    m_valDep.clear();
    m_valDep.append(valeurs);
    QList<int> res(valeurs);
    for(int ipos=0;ipos<=getPosMax();ipos++) {
        ReseauDeTri conns=getConnecteurs(ipos);
        foreach (Connecteur *c, conns) {
            if(res[c->getDepuis()]>res[c->getVers()]) {
                //qDebug()<<"Position "<<ipos<<" : on doit interchanger "<<res[c->getDepuis()]<<" avec "<<res[c->getVers()];
                int temp=res[c->getDepuis()];
                res[c->getDepuis()]=res[c->getVers()];
                res[c->getVers()]=temp;
                //qDebug()<<"------------- "<<Misc::toString(res)<<" -----------------";

                //qDebug()<<"Injection Historique";
            }
        }
    }
    m_valFin=res;
    return res;
}

bool ReseauDeTri::testZeroUn()
{
    // créer les 2^n suites composees de 0 ou de 1
    // on compte de 0 à 0b1111111
    int max=Misc::exp2(m_nbFils);
    for(int v=0; v<max; v++) {
        // on transforme le nombre v en liste de valeurs binaires
        QList<int> liste=Misc::toList(m_nbFils, v);
        //qDebug()<<Misc::toString(liste);
        QList<int> resultat=injecte(liste);
        bool ok=Misc::bienTrie(resultat);
        //qDebug()<<Misc::toString(liste)<<" -> "<<Misc::toString(resultat)<<" : "<<ok;
        if(!ok)
            return false;
    }
    return true;
}

int ReseauDeTri::testZeroUnVal()
{
    int res=0;
    // créer les 2^n suites composees de 0 ou de 1
    // on compte de 0 à 0b1111111
    int max=Misc::exp2(m_nbFils);
    for(int v=0; v<max; v++) {
        // on transforme le nombre v en liste de valeurs binaires
        QList<int> liste=Misc::toList(m_nbFils, v);
        //qDebug()<<Misc::toString(liste);
        QList<int> resultat=injecte(liste);
        bool ok=Misc::bienTrie(resultat);
        //qDebug()<<Misc::toString(liste)<<" -> "<<Misc::toString(resultat)<<" : "<<ok;
        if(!ok)
            res++;
    }
    return res;
}

void ReseauDeTri::parallele()
{
    // on tente de paralléliser les comparateurs
    bool yaeuunemodif=true;
    while(yaeuunemodif) {
        yaeuunemodif=false;
        foreach (Connecteur *c, *this) {
            int p=c->getPosition();
            if(p>0) {
                // on tente de décrémenter la position de ce connecteur
                ReseauDeTri prec=getConnecteurs(p-1);
                bool une_coincidence=false;
                foreach (Connecteur *c_1, prec) {
                    if(c_1->getDepuis() == c->getDepuis() || c_1->getDepuis() == c->getVers() ||
                            c_1->getVers() == c->getDepuis() || c_1->getVers() == c->getVers()) {
                        // une coincidence -> break
                        une_coincidence=true;
                        break;
                    }
                }
                if(!une_coincidence) {
                    //qDebug() <<"Je decremente la position du connecteur "<<c->toString();
                    c->decrementePosition();
                    //qDebug()<< toString();
                    yaeuunemodif=true;
                    break;
                }
            }
        }
    }
    std::sort(this->begin(), this->end(), Connecteur::lessDepuisThan);
    std::sort(this->begin(), this->end(), Connecteur::lessPositionThan);
}
