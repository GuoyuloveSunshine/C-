#include "Rect.h"
#include "Circle.h"
int main(int argn,char*argc[]){
    Shape *a_shape;
    if (1==argn||argc[1][0] == 'r'){
        Rect a_Rect;
        a_Rect.Set(2,3,4,5);
        a_shape=&a_Rect;
    }
    else{
        Circle a_circle;
        a_circle.Set(4,5,3);
        a_shape=&a_circle;
    }
    a_shape->Print();
    cout << "Area:"<< a_shape->Area()<<'\n';
    cout << "Circumference:"<<a_shape->Circumference()<<'\n';
    return 0;
}