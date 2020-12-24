#ifndef CONNECTEUR_H
#define CONNECTEUR_H

#include <QString>

class Connecteur
{
private:
    int m_position;
    int m_depart;
    int m_arrivee;
public:
    Connecteur(int pos, int dep, int arr);
    Connecteur(int dep, int arr);
    int getPosition() const;
    int getDepart() const;
    int getArrivee() const;
    void setDepart(int depart);
    void setArrivee(int arrivee);
    void setPosition(int position);
    void decrementePosition(){m_position--;}
    static bool lessPositionThan(Connecteur *c1, Connecteur *c2);
    static bool lessDepuisThan(Connecteur *c1, Connecteur *c2);
    QString toString();
};

#endif // CONNECTEUR_H
