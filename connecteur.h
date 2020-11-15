#ifndef CONNECTEUR_H
#define CONNECTEUR_H

#include <QString>

class Connecteur
{
private:
    int m_position;
    int m_depuis;
    int m_vers;
public:
    Connecteur(int p, int d, int v);
    Connecteur(int d, int v);
    int getPosition() const;
    int getDepuis() const;
    int getVers() const;
    QString toString();
    void decrementePosition() {m_position--;}
    static bool lessPositionThan(Connecteur *c1, Connecteur *c2);
    static bool lessDepuisThan(Connecteur *c1, Connecteur *c2);
    void setDepuis(int depuis);
    void setVers(int vers);
};

#endif // CONNECTEUR_H
