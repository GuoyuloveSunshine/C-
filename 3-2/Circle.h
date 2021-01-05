#include "Shape.h"
#define PI 3.14159
#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED


template <class T> class Circle : public Shape<T> {
  T x, y;
  T radius;
public:
  Circle():x(0), y(0), radius(0) {};
  Circle(T _x, T _y, T _r):x(_x), y(_y), radius(_r){};
  // getX() and getY() need to be implemented
  virtual T getX() const {return x;}
  virtual T getY() const {return y;}
  virtual T getRadius() const {return radius;}
  virtual T getWidth()  const {return 2 * radius;}
  virtual T getHeight() const {return 2 * radius;}
  virtual T getArea() const {return PI * radius * radius;}

};



#endif // CIRCLE_H_INCLUDED
