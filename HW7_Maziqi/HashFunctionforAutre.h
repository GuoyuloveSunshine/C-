#include <iostream>
using namespace std;

#define KEY_LENGTH 200
#define HASH_M2 1001
#define HASH_M 0x7FFF

template <class T>
int length(T& a) {
    int len=0;
    while(a[len]!=0) len++;
    return len;
}

// Integer comparison class
class IntCompare{
public:
	static bool lt(int x, int y){ return x < y; }
	static bool eq(int x, int y){ return x == y; }
	static bool gt(int x, int y){ return x > y; }
};

class IntsCompare{
public:
    static bool eq(int x[],int y[], int lenx,int leny){
        //cout<<"x= "<<length(x)<<endl;
        //cout<<"y= "<<length(y)<<endl;
        if(lenx>leny || lenx<leny) return false;
        for(int i=0;i<lenx;i++){
            //cout<<x[i];
            if(x[i]!=y[i]) return false;
        }
        return true;
    }
};

int ELFHash(int *key){
	unsigned long h = 0;
	while (*key){
		h = (h<<4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % HASH_M;  // second way: h & HASH_M
}

int ELFHash2(int* key){
	unsigned long h = 0;
	while (*key){
		h = (h<<4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % HASH_M2;
}

int DoubleHashingProbe(unsigned int hashTab[], int keyTab[][KEY_LENGTH], int key[])
{
	int h, h_org = h = ELFHash2(key);
	int h2 = (ELFHash(key)-3) % HASH_M2;
	int i;
	int* k;
    //for(int i=0;i<length(key);i++) cout<<key[i]<<",";
	if (!hashTab[h]){
		//cout << "HOME at Hash (" << key << ") = " << h << "  FREE" << endl;
		k = key; i = 0;
		while (*key) keyTab[h][i++] = *key++;
		keyTab[h][i] = '\0';
		hashTab[h] = h+1;
		return h;
	}
    int lenkT=length(keyTab[h]);
    //for (int i=0;i<lenkT;i++) cout<<keyTab[h][i]<<",";
    //cout<<endl;
    int lenk=length(key);
    //for (int i=0;i<lenkT;i++) cout<<key[i]<<",";
    //cout<<"lenkT:= "<<lenkT<<"lenk:= "<<lenk;

	if (IntsCompare::eq(keyTab[h], key,lenkT,lenk)){
		//cout << "Key [" << key << "] encountered again at slot " << h << endl;
		return h;
	}
	//cout << "HOME at Hash (" << key << ") = " << h << "  OCCUPIED => PROBE : " ;
	while (true){
		h += h2; h %= HASH_M2;
		//cout << "[" << h << "] ";
        int lenkT2=length(keyTab[h]);
        int lenk2=length(key);
		if (!hashTab[h]){ 
			//cout << "FREE SLOT PROBED" << endl;
			k = key; i = 0;
			while (*key) keyTab[h][i++] = *key++;
			keyTab[h][i] = '\0';
			hashTab[h] = h+1;
			return h;
		}
		else if (IntsCompare::eq(keyTab[h], key,lenkT2,lenk2)){
			//cout << "Key [" << key << "] encountered again at slot " << h << endl;
			return h;
		}
		else if (h==h_org){
			//cout << "NO FREE SLOT ANY MORE!" << endl;
			break;
		}
	}

	return 0;
}
