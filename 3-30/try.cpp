#include<string>
#include<iostream>
#include<math.h>
using namespace std;

int lengthOfLastWord(string s) {
        int pos=s.find_last_of(" ");
        while (pos==s.length()-1){
            if (s.length()==0) return 0;
            s.erase(pos,1);
            pos=s.find_last_of(" ");
        }
        return s.length()-pos-1;
}

int fac(int a){
    if (a==0) return 1;
    if (a==1) return a;
    else return a*fac(a-1);
}

int main(){
    //int a=5;
    // int m = a.find('a');
    // cout<<m<<endl;
    // a.erase(m,4);
    // cout<<a;
    //cout <<lengthOfLastWord(a);

    // string s1("Real Steel");
    // s1.replace(1, 3, "123456", 2, 4);  //用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
    // cout << s1 << endl;  //输出 R3456 Steel
    string a ="1111";
    string b="10001";
    cout<<min(a.length(),b.length());
    //HuangShang,ZhangWuJi,HongQiGong,HuangYaoShi,SaoDiSeng,WuYaZi,GuoJing,YangGuo,RenWoXing,ChongXuDaoZhang,XieXun,LingHuChong,FangZhengDaShi,DuGuQiuBai,DuanYu,QiaoFeng
    return 0;

}