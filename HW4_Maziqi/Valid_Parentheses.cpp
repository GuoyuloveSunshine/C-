#include<iostream>
#include<map>
#include<stack>
#include<string>
using namespace std;

int main(){
    map<char,char> brackets;
    brackets['(']=')';
    brackets[')']='(';
    brackets['[']=']';
    brackets[']']='[';
    brackets['{']='}';
    brackets['}']='{';
    stack<char> alist;
    alist.push('1');
    cout<<"Please input the parentheses: ";
    char c;
    while((c=cin.get())!='\n'){
        if (brackets[c]==alist.top()) alist.pop();
        else alist.push(c);
    }
    if (alist.top()=='1') cout<<"true";
    else cout <<"false";

    return 0;

}