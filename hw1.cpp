#include <iostream>
using namespace std;

int fun1(){
    int sum,b,n,i;
    cout << "Input the number of times you want to run:\n";
    cin >> n;
    cout << "Input a:\n";
    cin >> sum;
    for(i=0;i<n;i++)
    {
        cout <<"Input b:" << endl;
        cin >> b;
        sum = sum+b; 
        cout <<"sum=" << sum << endl;
    }
    return 0;
}

int main(){
    fun1();
}
