#include<iostream>
#include "operation1.h"
#include "operation2.h"
using namespace std;

int main(){
    
    while(1){
        cout<<"1 to traditional way, 0 to reversed way, q to quit \n Give me your chose:";
        char a;
        cin>>a;
        if (a=='q') break;
        else if(a=='1'){
            operation1* game = new operation1();
            game->Read();
            game->get24();
            show_one_res();
            delete game;
        }

        else if (a=='0'){
            operation2 *newgame = new operation2();
            newgame->Read();
            newgame->get24();
            show_one_res();
            delete newgame;

        }
    }
    return 0;
    
}