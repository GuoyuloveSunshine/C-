#include<iostream>
#include"Comp.h"
using namespace std;
template <class E,class Comp> void Mergesort(E A[],E temp[],int left,int right,map <string,int> dic){
    int mid=(left+right)/2;
    if(left==right) return;
    Mergesort<E,Comp>(A,temp,left,mid,dic);
    Mergesort<E,Comp>(A,temp,mid+1,right,dic);
    for (int i=left;i<=right;i++) temp[i]=A[i];
    int i1=left;int i2=mid+1;
    for(int curr=left;curr<=right;curr++){
        if (i1==mid+1) A[curr]=temp[i2++];
        else if (i2>right) A[curr]=temp[i1++];
        else if(Comp::big(temp[i1],temp[i2],dic)) A[curr]=temp[i1++];
        else A[curr]=temp[i2++];
    }
}