
#ifndef GUOYU_OPERATION_H
#define GUOYU_OPERATION_H

class operation{
public:

    virtual double Add(double,double)=0;
    virtual double Sub(double,double)=0;
    virtual double Mul(double,double)=0;
    virtual double Div(double,double)=0;
    virtual void Read()=0;

};
#endif 