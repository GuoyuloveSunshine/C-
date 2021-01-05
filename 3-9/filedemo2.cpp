#include <fstream>
//Attention: <fstream> instead of <iostream>
using namespace std;

int main()
{
	/*
	 * File: demo.in
	 * 3
	 * 1
	 * 4
	*/
	int num;
	ifstream fin; // input fstream
	ofstream fout; // output fstream
	fin.open("demo.in");
	fout.open("demo.out");

	while(fin >> num)
	{
		fout << num+1 << endl; 
	}

	fin.close(); fout.close();
	return 0;
}
