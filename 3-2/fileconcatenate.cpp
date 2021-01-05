#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int ch;
	ifstream f1("democat1");
	ifstream f2("democat2");
	ofstream f3("democat3");

	//file concatenation line by line
	while((ch=f1.get())!=-1)
		if ('\n'==ch)
			while ((ch=f2.get())!=-1){
				f3.put(ch);
				if ('\n'==ch) break;
			}
		else f3.put(ch);

	return 0;
}
