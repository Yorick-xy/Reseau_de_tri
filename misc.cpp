#include "misc.h"
#include <QTextStream>

QString Misc::toString(const QList<int> &l)
{
    QString res;
    QTextStream buf(&res);
    foreach (int v, l) {
        buf<<v<<" ";
    }
    return res;
}

QList<int> Misc::toList(int nb, int v)
{
    QList<int> res;
    for(int i=0; i<nb; i++) {
        res.prepend(v%2);
        v/=2;
    }
    return res;
}

bool Misc::bienTrie(const QList<int> &l)
{
    for(int i=0; i<l.size()-1; i++) {
        if(l[i]>l[i+1])
            return false;
    }
    return true;
}

void Misc::swap(int &i, int &j)
{
    int t=i;
    i=j;
    j=t;
}

double Misc::abs(double v)
{
    return v<0?-v:v;
}
