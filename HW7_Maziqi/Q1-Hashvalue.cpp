#include <iostream>
#include <string>
#include<fstream>
#include"HashFunctionforQ1.h"
using namespace std;

int main(int argn, char* argc[])
{
	string buf;
	int aLine[KEY_LENGTH];
	int keyTab[HASH_M2][KEY_LENGTH];
	static unsigned int hashTab[HASH_M2];

	int count=0;
	ifstream fin;
	fin.open("DataHeapHashHW");
	while (getline(fin,buf)){
		int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
		//cout<<buf<<endl;

		int b = DoubleHashingProbe(hashTab,keyTab,aLine);
		count++;
		cout << "* " << buf << "\n";
		cout << nCHN << " Chinese characters : ";
		//cout<<aLine[0];
		for (int k=0; k<nCHN; k++) cout << aLine[k] << " ";
		cout << "\n";
		cout<<"The Hash number for this int array is: "<< b <<endl<<endl;
        for(int j=0;j<nCHN;j++) aLine[j]=0;
	}
	//cout<<count;
	fin.close();
	while(1){
		cout<<"you can type your own array (in form of 111,222,333...), use q to quit:"<<endl;
		string a;
		cin>>a;
		if (a =="q") break;
		int mynum[1000]={0};
		int lenmy=0;
		while(a.find(',')!=string::npos){
			int n= a.find(',');
			mynum[lenmy++]=stoi(a.substr(0,n));
			a.erase(0,n+1);
		}
		mynum[lenmy++]=stoi(a);
		cout<<"Your array: ";
		for (int i=0;i<lenmy;i++) cout<<mynum[i]<<" ";
		cout<<endl;
		int c = DoubleHashingProbe(hashTab,keyTab,mynum);
		cout<<"The Hash number for this int array is: "<< c <<endl<<endl;
	}

	return 0;
}

