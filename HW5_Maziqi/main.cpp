#include <iostream>
#include <map>
#include <string>
#include<fstream>
#include "Quicksort.h"
#include "Mergesort.h"
using namespace std;


template<class E> void print(E A[],int n){
for (int i=0;i<n;i++){
    cout<<A[i]<<' ';
}
    cout<<endl;
};

int main(){
    //read the levels txt document and put them into a map.
    map <string,int>  levels;
    ifstream infile;
    infile.open("bud.txt", ios::in);
    string deal_s;
    while(getline(infile,deal_s)){
        int colon_index = deal_s.find(':');
        string level_s;
        level_s = deal_s.substr(6,colon_index);
        int lv = stoi(level_s);
        deal_s.erase(0,colon_index+1);
        while(deal_s.find(';')!=string::npos){
            int semi_idx = deal_s.find(';');
            string name_tmp = deal_s.substr(0,semi_idx);
            deal_s.erase(0,semi_idx+1);
            levels[name_tmp] = lv;
        }
        if(deal_s[deal_s.length()-1]=='\n')deal_s = deal_s.substr(0,deal_s.length()-2);
        string name_tmp = deal_s;
        levels[name_tmp] = lv;
    }
    infile.close();



    string arr,temp;
    cout<< "Please input the name with the forme A,B,C,D......: "<<endl;
    //for exemple: HuangShang,ZhangWuJi,HongQiGong,HuangYaoShi,SaoDiSeng,WuYaZi,GuoJing,YangGuo,RenWoXing,ChongXuDaoZhang,XieXun,LingHuChong,FangZhengDaShi,DuGuQiuBai,DuanYu,QiaoFeng
    cin>>arr;
    string test_q[50]={};
    string test_m[50]={};
    string templ[50]={};
    int len=0;
    while(arr.find(',')!=string::npos){
        temp=arr.substr(0,arr.find(","));
        arr.erase(0,arr.find(",")+1);
        test_q[len]=temp;
        test_m[len++]=temp;
    }
    test_q[len]=arr;
    test_m[len++]=arr;
    

    QuickSort<string,Compdic>(test_q,0,len-1,levels);
    cout<<"The results of QuickSort: \n";
    print<string>(test_q,len);
    Mergesort<string,Compdic>(test_m,templ,0,len-1,levels);
    cout<<"The results of MergeSort: \n";
    print<string>(test_m,len);
    //if(levels.find("111")==levels.end()) cout<<"111";
    return 0;
}