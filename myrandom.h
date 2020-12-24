#ifndef MYRANDOM_H
#define MYRANDOM_H


class MyRandom
{
public:
    MyRandom(int seed=-1);
    int get(int max);
    double getFloat();
};

#endif // MYRANDOM_H
