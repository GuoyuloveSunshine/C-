#include "DLLink.h"
#include<iostream>
using namespace std;
int main(){
    int a,b,left,right;
    DLLink<int> dl;
    cout<<"Test the insert function: ";
    dl.insert(3);
    dl.insert(4);
    dl.insert(5);
    dl.insert(1);
    dl.insert(2);
    dl.insert(9);
    dl.insert(10);
    dl.insert(30);
    dl.insert(40);
    dl.print();
    cout<<"Test the append function: ";
    dl.append(50);
    dl.print();
    cout<<"Test the set end function: ";
    dl.setEnd();
    dl.print();
    cout<<"Test the set start function: ";
    dl.setStart();
    dl.print();
    cout<<"Test the set position function: ";
    dl.setPos(4);
    dl.print();
    cout<<"Test the remove function: ";
    dl.remove(a);
    dl.print();
    cout<<"The number that we just removed is: "<<a<<endl;
    cout<<"Test the go-previous function: ";
    dl.prev();
    dl.print();
    cout<<"Test the go-next position function: ";
    dl.next();
    dl.print();
    cout<<"Test the get value function: ";
    dl.getValue(b);
    dl.print();
    cout<<"The value that we get is:"<<b<<endl;
    cout<<"Test the get-leftlength and get-rightlength function: ";
    left=dl.leftLength();
    right=dl.rightLength();
    dl.print();
    cout<<"The left-length is: "<<left<<", the right-length is: "<<right<<endl;
    cout<<"When the position is out of range, the list does not change: ";
    dl.setPos(-1);
    dl.print();
    return 0;
    
    
}