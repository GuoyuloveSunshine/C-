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

	while(!fin.eof())
	{	fin >> num; // read from fin
		fout << num+1 << endl; 
	}
	/*eof() does not return True
	 * when it arrives at the file end
	 * but when it has passed the file end
	*/

	fin.close(); fout.close();
	return 0;
}
