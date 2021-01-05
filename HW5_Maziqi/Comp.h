#ifndef COMP_H
#define COMP_H
#include<map>
#include <string>
#include<iostream>
using namespace std;
class Compdic{
public:

    static bool small(string x,string y,map<string,int> a){return a[x]<a[y];}
    static bool equaux(string x,string y,map<string,int> a){return a[x]==a[y];}
    static bool big(string x, string y, map<string,int> a){return a[x]>a[y];}
};

template <class Elem>
inline void swap(Elem A[], int i, int j){
	Elem temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
#endif
