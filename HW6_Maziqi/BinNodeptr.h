#include "BinNode.h"
#include<stdlib.h>
#include<iostream>
using namespace std;


template <class Elem>
class BinNodeptr: public BinNode<Elem>{
private:
    Elem it;
    BinNodeptr *lc;
    BinNodeptr *rc;
public:
    BinNodeptr(){lc=rc=NULL;}
    BinNodeptr(Elem e,BinNodeptr *left=NULL,BinNodeptr *right=NULL){
        it=e;lc=left;rc=right;
    }
    ~BinNodeptr(){};
    Elem &val() {return it;}
    void setVal(const Elem &e){it = e;}
    inline BinNode<Elem>* left() const {return lc;}
    void setLeft(BinNode<Elem> *b){lc = (BinNodeptr*)b;}
    inline BinNode<Elem>* right() const {return rc;}
    void setRight(BinNode<Elem> *b){rc = (BinNodeptr*)b;}
    bool isLeaf(){return (lc==NULL)&(rc==NULL);}
};