#include <iostream>
using namespace std;

class PQ
{
    private:

    int *pArray;
    int m_length;

    public:

    PQ(int N){
        pArray = new int[N+1];
        m_length = 0;
    }

    int delMin(){
        int min = pArray[1];
        swap(pArray[1],pArray[m_length--]);
        pArray[m_length+1] = nullptr;
        sink(1);
        return min;
    }

    void insert(int v){
        pArray[++m_length] = v;
        swim(m_length);
    }

    bool isEmpty(){
        return m_length == 0;
    }

    int size(){
        return m_length;
    }

    void swim(int k){
        while(k>1 && pArray[k]<pArray[k/2]){
            swap(pArray[k/2],pArray[k]);
            k /= 2;
        }
    }

    void sink(int k){
        while( 2*k <= m_length){
            int j=2*k;
            if(j<m_length && (pArray[j]>pArray[j+1]))j++;
            if(pArray[k]<pArray[j])break;
            swap(pArray[k],pArray[j]);
            k=j;
        }
    }

    int val() const{ return pArray;}
};

int main(){
    PQ shazi(10);
    shazi.insert(1);
    shazi.insert(9);
    shazi.insert(8);
    cout<<shazi
}