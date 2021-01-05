#include <iostream>
#include "Shape.h"

using namespace std;

class Rect: public Shape
{
private:
	double x, y, w, h;
public:
	Rect(){}
	~Rect(){}
	void Set(double in_x, double in_y, double in_w, double in_h)
	{ x = in_x; y = in_y; w = in_w; h = in_h; }
	double Area(){ return w*h; }
	double Circumference(){ return 2*(w+h); }
	void Print()
	{ cout << "Located at (" << x << "," << y << ") with width " << w << " and height " << h << endl; } 
};
