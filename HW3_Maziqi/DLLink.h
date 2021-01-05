#ifndef DLLINK_H
#define DLLINK_H

#include<iostream>
#include "List.h"
#define DEFAULT_LIST_SIZE 100
using namespace std;

template <class Elem> class Link{
public:
    Elem element;
    Link *next;
    Link *prev;
    Link(const Elem & e,Link *prevp = NULL,Link *nextp=NULL){
        element=e;
        next=nextp;
        prev=prevp;
    }
    Link(Link *prevp=NULL,Link *nextp=NULL){
        next=nextp;
        prev=prevp;
    }
};

template <class Elem> class DLLink: public List<Elem>{
private:
    Link<Elem> *head;
    Link<Elem> *fence;
    Link<Elem> *tail;
    int leftcnt;
    int rightcnt;
    void init(){
        head=fence=new Link<Elem>;
        tail=head->next;
        leftcnt=rightcnt=0;
    }
    void removeall(){
        Link<Elem> *temp;
        while(head!=NULL){
            temp=head;
            head=head->next;
            delete temp;
        }
    }
public:
    DLLink(int size=DEFAULT_LIST_SIZE){init();}
    ~DLLink(){removeall();}
    void clear(){
        removeall();
        init();
    }
    bool insert(const Elem&);
    bool append(const Elem&);
    bool remove(Elem&);
    void setStart(){
        fence=head;
        rightcnt+=leftcnt;
        leftcnt=0;
    }
    void setEnd(){
        fence=tail;
        leftcnt+=rightcnt;
        rightcnt=0;
    }
    void prev(){
        if (fence!=head) fence=fence->prev;
    }
    void next(){
        if(fence!=tail) fence=fence->next;
    }
    int leftLength() const{
        return leftcnt;
    }
    int rightLength() const{
        return rightcnt;
    }
    bool setPos(int Pos){
        if((Pos<0)||Pos>rightcnt+leftcnt) return false;
        while(leftcnt!=Pos){
            if (leftcnt>Pos) {fence=fence->prev;leftcnt--;rightcnt++;}
            if (leftcnt<Pos) {fence=fence->next;leftcnt++;rightcnt--;}
        }
        return true;
    }
    bool getValue(Elem&it) const{
        if (rightLength()==0) return false;
        it=fence->next->element;
        return true;
    }
    void print() const; 

};


template <class Elem> bool DLLink<Elem>::insert(const Elem &a){
    Link<Elem> *temp = new Link<Elem>(a,fence,fence->next);
    if(fence->next){
        fence->next->prev = temp;
    }
    else{
        tail = temp;
    }
    fence->next = temp;
    
    if(fence==tail) tail=fence->next;
    rightcnt++;
    return true;
}

template <class Elem> bool DLLink<Elem>::append(const Elem &a){
    Link<Elem> *temp=new Link<Elem>(a,tail,NULL);
    tail=tail->next=temp;
    rightcnt++;
    return true;
}

template<class Elem> bool DLLink<Elem>::remove(Elem &a){
    if (fence->next==NULL) return false;
    a=fence->next->element;
    Link<Elem> *temp=fence->next;
    fence->next = temp->next;
    temp->next->prev=fence;
    rightcnt--;
    delete temp;
    return true;
}

template<class Elem> void DLLink<Elem>::print()const{
    Link<Elem> *temp=head;
    cout << "< ";
	while(temp != fence){
		cout << temp->next->element << " ";
		temp = temp -> next;
	}
	cout << "| ";
	while(temp->next != NULL){
		cout << temp->next->element << " ";
		temp = temp -> next;
	}
	cout << ">\n";
}
#endif
