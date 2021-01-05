#ifndef __SHAPE_H__
#define __SHAPE_H__
class Shape
{
public:
	virtual double Area() = 0;
	virtual double Circumference() = 0;
	virtual void Print() = 0;
};
#endif
