#ifndef OPERATION2_H
#define OPERATION2_H

#include "base24.h"


class operation2: public base24
{
    public:
    operation2(){}
    ~operation2(){}
    double Add(double a,double b){return a-b;}
    double Sub(double a,double b){return a+b;}
    double Mul(double a,double b){return a/b;}
    double Div(double a,double b){return a*b;}   
};

#endif
