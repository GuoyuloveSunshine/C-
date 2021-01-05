#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > list;
    while(1){
        int len;
        cout<<"Please input the number of pile:  ";
        cin>>len;
        cin.get();
        char stri[1000]={};
        cout<<"Please input the mass of pile (in form of 1 2 3 4 5...): ";
        cin.getline(stri,1000);
        string str=string(stri); //deal with input, put them in a priority queue.

        while(str.find(' ')!=string::npos){
            int n=str.find(' ');
            list.push(stoi(str.substr(0,n)));
            str.erase(0,n+1);
        }
        list.push(stoi(str));
        if (list.size()==len) break;
        else cout<<"The length and the mass aren't correspodant, please input again."<<endl;
        while(!list.empty()) list.pop();
    }

    int cost=0;
    if (list.size()==1){
        cost+=list.top();
    }
    else{
        while (list.size()!=1){
            int min1=list.top();
            list.pop();
            int min2=list.top();
            list.pop();
            cost+=min1+min2;
            cout<<"m1 = "<<min1<<", m2 = "<<min2<<", cost ="<<cost<<endl;
            list.push(min1+min2);
        }
    }

    cout<<"The final cost is: "<<cost;
    return 0;
}