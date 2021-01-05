#include <iostream>
#include <string>
#include<fstream>
#include"HashFunctionforAutre.h"
using namespace std;

bool isinarray(int arr[],int len,int Hash){
    int a=0;
    while(a<len){
        if (arr[a]==Hash) return true;
        a++;
    }
    return false;
}

int main(int argn, char* argc[])
{
	string buf;
	int aLine[KEY_LENGTH]={0};
	int keyTab[HASH_M2][KEY_LENGTH];
	static unsigned int hashTab[HASH_M2];
    
    int arr[HASH_M2];
    string res[HASH_M2];
    int lenr=0;

	ifstream fin;
	fin.open("DataHeapHashHW");
	while (getline(fin,buf)){
		int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
		int b=DoubleHashingProbe(hashTab,keyTab,aLine);
        if(!isinarray(arr,lenr,b)){
            arr[lenr]=b;
            res[lenr]=buf;
            lenr++;
        }
		// cout << "* " << buf << "\n";
		// cout << nCHN << " Chinese characters : ";
		// //cout<<aLine[0];
		// for (int k=0; k<nCHN; k++) cout << aLine[k] << " ";
		// cout << "\n";
        for(int j=0;j<nCHN;j++) aLine[j]=0;
	}
    fin.close();
    for (int j=0;j<lenr;j++) cout<<arr[j]<<","<<res[j]<<endl;
    cout<<endl;
    cout<<"There are totally "<< lenr<<" sentences different."<<endl;
	return 0;
}

