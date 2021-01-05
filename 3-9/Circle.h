#include <iostream>
#include "Shape.h"

using namespace std;

class Circle: public Shape
{
private:
	double x, y, r;
public:
	Circle(){}
	~Circle(){}
	void Set(double in_x, double in_y, double in_r)
	{ x = in_x; y = in_y; r = in_r; }
	double Area(){ return 3.14*r*r; }
	double Circumference(){ return 2*3.14*r; }
	void Print()
	{ cout << "Located at (" << x << "," << y << ") with radius " << r << endl; }
};
