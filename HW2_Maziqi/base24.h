#ifndef BASE24_H
#define BASE24_H

#include "operation.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const double err = 1e-3;
string res[1000];
int res_len = 0;

void copyarray(double num[],double temp[],int i,int j,int len);
string copy(string a,string arr,double num[],int m,int n,int round);
int occurrences (string str,string dest);
bool rest1(string str,string dest);
bool right_range(int a);
void show_one_res();
void add_to_res(string s);

class base24: public operation{
private:
    double num[4];
public:
    base24();
    ~base24();
    void Read();
    void get24();
    double Add(double,double){}
    double Sub(double,double){}
    double Mul(double,double){}
    double Div(double,double){}
};

base24::base24(){
    for(int i=0;i<4;++i){
        num[i] = 0;
    }
}

base24::~base24(){
    for(int i=0;i<res_len;++i){
        res[i] = "";
    }
    res_len = 0;
}

//the input function

void base24::Read(){
    while(1){
        cout <<"Please input 4 integers from 1 to 13:\n";
        cin >> num[0] >> num[1]>>num[2]>> num[3];
        if(right_range(num[0])&&right_range(num[1])&&right_range(num[2])&&right_range(num[3])) break;
        else cout<<"Invalid input, please try again."<<endl;
    }
}

//then I define my algorithm to calculate 24 in which I use enumerating method. 
//First of all, I combine 2 numbers in 4, it has 6 probabilities and each case can be mingled with 8 calculators, so 
//in the first round, we have 6*8 array of size three, then with using the identical method as before in each array,
//, this time I get a 48*24 array of size 2, then I calculate to see whether the final resultats is 24
// if yes, I store the case in a string array.  Finally, I print out one of the resultats in my string array.
void base24::get24(){
    string none="";
    double firstround[48][3]={0};
    string firstremem[48];
    int a=0;
    for(int i=0;i<3;i++){
        for (int j=i+1;j<4;j++){
            firstround[a][0]=Add(num[i],num[j]);copyarray(num,firstround[a],i,j,4);firstremem[a]=copy("Add",none,num,i,j,1);
            firstround[a+1][0]=Add(num[j],num[i]);copyarray(num,firstround[a+1],i,j,4);firstremem[a+1]=copy("Add",none,num,j,i,1);
            firstround[a+2][0]=Sub(num[i],num[j]);copyarray(num,firstround[a+2],i,j,4);firstremem[a+2]=copy("Sub",none,num,i,j,1);
            firstround[a+3][0]=Sub(num[j],num[i]);copyarray(num,firstround[a+3],i,j,4);firstremem[a+3]=copy("Sub",none,num,j,i,1);
            firstround[a+4][0]=Mul(num[i],num[j]);copyarray(num,firstround[a+4],i,j,4);firstremem[a+4]=copy("Mul",none,num,i,j,1);
            firstround[a+5][0]=Mul(num[j],num[i]);copyarray(num,firstround[a+5],i,j,4);firstremem[a+5]=copy("Mul",none,num,j,i,1);
            firstround[a+6][0]=Div(num[i],num[j]);copyarray(num,firstround[a+6],i,j,4);firstremem[a+6]=copy("Div",none,num,i,j,1);
            firstround[a+7][0]=Div(num[j],num[i]);copyarray(num,firstround[a+7],i,j,4);firstremem[a+7]=copy("Div",none,num,j,i,1);
            a+=8;

        }
    }


    double seconderound[48*3*8][2]={0};
    string seconderemem[48*3*8];
    int b=0;
    for(int m=0;m<48;m++){
        for(int i=0;i<2;i++){
            for (int j=i+1;j<3;j++){
                seconderound[b][0]=Add(firstround[m][i],firstround[m][j]);copyarray(firstround[m],seconderound[b],i,j,3);seconderemem[b]=copy("Add",firstremem[m],firstround[m],i,j,2);
                seconderound[b+1][0]=Add(firstround[m][j],firstround[m][i]);copyarray(firstround[m],seconderound[b+1],i,j,3);seconderemem[b+1]=copy("Add",firstremem[m],firstround[m],j,i,2);
                seconderound[b+2][0]=Sub(firstround[m][i],firstround[m][j]);copyarray(firstround[m],seconderound[b+2],i,j,3);seconderemem[b+2]=copy("Sub",firstremem[m],firstround[m],i,j,2);
                seconderound[b+3][0]=Sub(firstround[m][j],firstround[m][i]);copyarray(firstround[m],seconderound[b+3],i,j,3);seconderemem[b+3]=copy("Sub",firstremem[m],firstround[m],j,i,2);
                seconderound[b+4][0]=Mul(firstround[m][i],firstround[m][j]);copyarray(firstround[m],seconderound[b+4],i,j,3);seconderemem[b+4]=copy("Mul",firstremem[m],firstround[m],i,j,2);
                seconderound[b+5][0]=Mul(firstround[m][j],firstround[m][i]);copyarray(firstround[m],seconderound[b+5],i,j,3);seconderemem[b+5]=copy("Mul",firstremem[m],firstround[m],j,i,2);
                seconderound[b+6][0]=Div(firstround[m][i],firstround[m][j]);copyarray(firstround[m],seconderound[b+6],i,j,3);seconderemem[b+6]=copy("Div",firstremem[m],firstround[m],i,j,2);
                seconderound[b+7][0]=Div(firstround[m][j],firstround[m][i]);copyarray(firstround[m],seconderound[b+7],i,j,3);seconderemem[b+7]=copy("Div",firstremem[m],firstround[m],j,i,2);
                b+=8;
            }

        }

    }

    for (int i=0;i<48*24;i++){
        int flag=0;
        string final="";
        string dest=",";
        string tmp_res = "";
        if (24-err<=Add(seconderound[i][0],seconderound[i][1])&&Add(seconderound[i][0],seconderound[i][1])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Add("+seconderemem[i]+","+std::to_string(seconderound[i][1])+")";
            }
            else{
                tmp_res = final+"Add("+seconderemem[i]+","+firstremem[i/24]+")";
            }
        }
        if (24-err<=Add(seconderound[i][1],seconderound[i][0])&&Add(seconderound[i][1],seconderound[i][0])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Add("+std::to_string(seconderound[i][1])+","+seconderemem[i]+")";
            }
            else{
                tmp_res = final+"Add("+firstremem[i/24]+","+seconderemem[i]+")";
            }
        }

        if (24-err<=Sub(seconderound[i][0],seconderound[i][1])&&Sub(seconderound[i][0],seconderound[i][1])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Sub("+seconderemem[i]+","+std::to_string(seconderound[i][1])+")";
            }
            else{
                tmp_res = final+"Sub("+seconderemem[i]+","+firstremem[i/24]+")";
            }
        }

        if (24-err<=Sub(seconderound[i][1],seconderound[i][0])&&Sub(seconderound[i][1],seconderound[i][0])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Sub("+std::to_string(seconderound[i][1])+","+seconderemem[i]+")";
            }
            else{
                tmp_res = final+"Sub("+firstremem[i/24]+","+seconderemem[i]+")";
            }
        }

        if (24-err<=Mul(seconderound[i][0],seconderound[i][1])&&Mul(seconderound[i][0],seconderound[i][1])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Mul("+seconderemem[i]+","+std::to_string(seconderound[i][1])+")";
            }
            else{
                tmp_res = final+"Mul("+seconderemem[i]+","+firstremem[i/24]+")";
            }
        }
        if (24-err<=Mul(seconderound[i][1],seconderound[i][0])&&Mul(seconderound[i][1],seconderound[i][0])<=24+err) {

            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Mul("+std::to_string(seconderound[i][1])+","+seconderemem[i]+")";
            }
            else{
                tmp_res = final+"Mul("+firstremem[i/24]+","+seconderemem[i]+")";
            }
        }

        if (24-err<=Div(seconderound[i][0],seconderound[i][1])&&Div(seconderound[i][0],seconderound[i][1])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Div("+seconderemem[i]+","+std::to_string(seconderound[i][1])+")";
            }
            else{
                tmp_res = final+"Div("+seconderemem[i]+","+firstremem[i/24]+")";
            }
        }
        if (24-err<=Div(seconderound[i][1],seconderound[i][0])&&Div(seconderound[i][1],seconderound[i][0])<=24+err) {
            if(rest1(seconderemem[i],dest)){
                tmp_res = final+ "Div("+std::to_string(seconderound[i][1])+","+seconderemem[i]+")";
            }
            else{
                tmp_res = final+"Div("+firstremem[i/24]+","+seconderemem[i]+")";
            }
        }

        if(tmp_res.length()>0){
            add_to_res(tmp_res);
        }
    }
}

void copyarray(double num[],double temp[],int i,int j,int len){
    int a =1;
    for(int m=0;m<len;m++){
        if (m!=i&&m!=j) {
            temp[a]=num[m];
            a++;
        }
    }
}

string copy(string a,string arr,double num[],int m,int n,int round){
    if(round==1) return arr+a+"("+std::to_string(num[m])+","+std::to_string(num[n])+")";
    if(round==2) {
        if (m==0) {return a+"("+arr+","+std::to_string(num[n])+")";}
        else if (n==0) return a+"("+std::to_string(num[m])+","+arr+")";
        else return a+"("+std::to_string(num[m])+","+std::to_string(num[n])+")";
    }
}

int occurrences (string str,string dest) {
    size_t pos, pre = 0, count = 0;
    while ( (pos = str.find(dest, pre)) != std::string::npos ) {
        ++count;
        pre = pos + 1;
    }
    return count;
};


bool rest1(string str,string dest){
    if (occurrences(str,dest)==2) return true;
    else return false;
}

bool right_range(int a){
    if(a>0 && a<14)return 1;
    return 0;
}

void show_one_res(){
    if(res_len==0)cout<<"No answer found."<<endl;
    else cout<<res[0]<<endl;
}

void add_to_res(string s){
    res[res_len++] = s;
}



#endif