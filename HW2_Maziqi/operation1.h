#ifndef OPERATION1_H
#define OPERATION1_H


#include "base24.h"


class operation1: public base24
{
    public:
    operation1(){}
    ~operation1(){}
    double Add(double a,double b){return a+b;}
    double Sub(double a,double b){return a-b;}
    double Mul(double a,double b){return a*b;}
    double Div(double a,double b){return a/b;}   
};

#endif
