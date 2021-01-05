#include<queue>
#include<iostream>
using namespace std;
string MAX="2147483647";
string MIN="-2147483648";

int main(){
    queue<int> list;
    string str,temp;
    int k,num;
    int te,max;
    cout<<"Pleasse input the numbers smaller than 2147483647 and bigger than -2147483648 and in form of 1,2,3,4,5...etc: ";
    cin>>str;
    cout<<"Please input the slide windows: ";
    cin>>k;
    while(str.find(',')!=string::npos){
        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1,str.size());
        num=atoi(temp.c_str());

        if (list.size()<k) list.push(num);
        else {
            list.pop();
            list.push(num);
        }
        if (list.size()==k){
            
            max=list.front();
            for(int i=0;i<k;i++){
                te=list.front();
                list.pop();
                if (te>max) max=te;
                list.push(te);  
            }
            cout<<max<<',';
        }
    }
    num=atoi(str.c_str());
    if (list.empty()) {
        max=num;
    }
    else{
        list.pop();
        list.push(num);
        max=list.front();
        //cout<<"max:"<<max<<endl;
        for(int i=0;i<k;i++){
            te=list.front();
            list.pop();
            if (te>max) max=te;
            list.push(te); 
        }
    }
    cout<<max;     
    //cout<<str<<endl<<str.size()<<endl<<str.find(',')<<endl;
    
    
    
    //cout<<<<endl<<str<<endl;
    return 0;
}