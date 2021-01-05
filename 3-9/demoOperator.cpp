#include <iostream>

using namespace std;

class Point2D{
public:
	double x, y;
	Point2D(){}
	Point2D(double in_x, double in_y){ x = in_x; y = in_y; }
	void Print(){ cout << "Point (" << x << "," << y << ")"; }
};

// Attention: operator should take at least one non-default-data-type argument
Point2D operator + (Point2D P1, Point2D P2){
	Point2D ret; ret.x = P1.x + P2.x; ret.y = P1.y + P2.y;
	return ret;
}

int main()
{
	Point2D A(5,3), B(-2,4), C;
	C = A+B; 
	A.Print(); cout << " + "; B.Print(); cout << " = "; C.Print(); cout << endl;

	return 0;
}
