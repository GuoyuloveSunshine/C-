#include <iostream>
#include <fstream>
using namespace std;

int filesum(char* filename)
{
	ifstream fin(filename);
	int sum = 0, value;
	//read until non-integer or the file end
	while (fin >> value)
		sum += value;
	return sum;
}

int main()
{
	char filename[] = "demo.in";
	int sum = filesum(filename);
	cout << "Sum of numbers: " << sum << endl;
	return 0;
}
