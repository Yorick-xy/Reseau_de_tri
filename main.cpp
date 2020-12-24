#include <QCoreApplication>
#include <iostream>
#include "../shared/qstd.h"
#include "individual.h"
using namespace qstd;

int main(int argc, char *argv[])
{
    cout << "=================" << Qt::endl;
    cout << "= RESEAU DE TRI =" << Qt::endl;
    cout << "=================" << Qt::endl;

    Individual *Locky = new Individual();
    Locky->run();

    return 0;
}
