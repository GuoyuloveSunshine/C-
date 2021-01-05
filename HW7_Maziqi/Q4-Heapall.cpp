#include <iostream>
#include <string>
#include<fstream>
#include<ostream>
#include"HashFunctionforAutre.h"
#include"MinHeap.h"
using namespace std;

int main(int argn, char* argc[])
{
	string buf;
	int aLine[KEY_LENGTH]={0};
	int keyTab[HASH_M2][KEY_LENGTH];
	static unsigned int hashTab[HASH_M2];
    
    Mylist arry[100];
    MinHeap<Mylist,MyListCompare> hp(arry,0,100);
    int num=0;
	ifstream fin;
	fin.open("DataHeapHashHW");
	while (getline(fin,buf)){
        num++;
		int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
		int Hash=DoubleHashingProbe(hashTab,keyTab,aLine);
        Mylist temp;
        temp.Hashnum=Hash;
        temp.chinese=buf;
        if(hp.heapsize()<100 &&!(hp.isinHeap(temp))){
            hp.insert(temp);
        }

        for(int j=0;j<nCHN;j++) aLine[j]=0;
	}
    fin.close();
    ofstream fout;
    fout.open("HeapAll.dat");
    for (int i=0 ;i<hp.heapsize();i++){
        fout<<"Hash num: "<<hp.extract(i).Hashnum<<" , sentence: "<<hp.extract(i).chinese<<endl;
    }
    fout.close();
	return 0;
}

