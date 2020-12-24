#include "myrandom.h"
#include <QDateTime>

MyRandom::MyRandom(int seed)
{
    if(seed!=-1)
        qsrand(seed);
    else
        qsrand(QDateTime::currentMSecsSinceEpoch()/1000);
}

int MyRandom::get(int max)
{
    return qrand()%max;
}

double MyRandom::getFloat()
{
    return (qrand()%1000)/1000.0;
}
