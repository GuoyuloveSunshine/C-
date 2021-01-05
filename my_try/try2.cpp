#include <iostream>
using namespace std;
class Stock{
public:
Stock(){
    cout<<"I am created!"<<endl;
}
Stock(const char* name,int price){
    cout<<"I am created with parameters"<<endl;
    }
~Stock(){
    cout<<"I am destroyed"<<endl;
}
};
int main(){
    Stock s;
    cout<<'\n';
    Stock *p= new Stock("Google",100);
    cout<<'\n';
    // delete p;
    // cout<<'\n';
    return 0;
}