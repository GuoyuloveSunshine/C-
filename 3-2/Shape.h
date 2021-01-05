
#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

template <class T> class Shape {  // interface
public:
  virtual T getX() const = 0;                 // abstract
  virtual T getY() const = 0;                 // abstract
  virtual T getWidth()  const = 0;   // abstract
  virtual T getHeight() const = 0;   // abstract
  virtual T getArea() const = 0;     // abstract
};


#endif // SHAPE_H_INCLUDED
