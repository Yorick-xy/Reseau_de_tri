#ifndef MISC_H
#define MISC_H

#include <QList>
#include <cmath>

class Misc
{
public:
    static QString toString(const QList<int> &l);
    static int exp2(int v){return pow(2, v);}
    static QList<int> toList(int nb, int v);
    static bool bienTrie(const QList<int> &l);
    static void swap(int& i, int& j);
    static double abs(double v);
};

#endif // MISC_H
