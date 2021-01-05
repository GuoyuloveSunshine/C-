#include <iostream>
#include<fstream>
#include "ELFHash.h"
#include "Compare.h"
using namespace std;

#define KEY_LENGTH 200

#define HASH_M2 11
int ELFHash2(char* key){
	unsigned long h = 0;
	while (*key){
		h = (h<<4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % HASH_M2;
}

int DoubleHashingProbe(unsigned int hashTab[], char keyTab[][KEY_LENGTH], char* key)
{
	int h, h_org = h = ELFHash2(key);
	int h2 = (ELFHash(key)-3) % HASH_M2;
	int i;
	char* k;
	if (!hashTab[h]){
		cout << "HOME at Hash (" << key << ") = " << h << "  FREE" << endl;
		k = key; i = 0;
		while (*key) keyTab[h][i++] = *key++;
		keyTab[h][i] = '\0';
		cout<<"11"<<keyTab[h]<<endl;
		hashTab[h] = h+1;
		return h;
	}

	if (CharsCompare::eq(keyTab[h], key)){
		cout << "Key [" << key << "] encountered again at slot " << h << endl;
		return h;
	}
	cout << "HOME at Hash (" << key << ") = " << h << "  OCCUPIED => PROBE : " ;
	while (true){
		h += h2; h %= HASH_M2;
		cout << "[" << h << "] ";
		if (!hashTab[h]){ 
			cout << "FREE SLOT PROBED" << endl;
			k = key; i = 0;
			while (*key) keyTab[h][i++] = *key++;
			keyTab[h][i] = '\0';
			hashTab[h] = h+1;
			return h;
		}
		else if (CharsCompare::eq(keyTab[h], key)){
			cout << "Key [" << key << "] encountered again at slot " << h << endl;
			return h;
		}
		else if (h==h_org){
			cout << "NO FREE SLOT ANY MORE!" << endl;
			break;
		}
	}

	return 0;
}

int main(){
	char key[KEY_LENGTH];
	char keyTab[HASH_M2][KEY_LENGTH];
	static unsigned int hashTab[HASH_M2];
	ifstream fin;
	fin.open("txteg2");
	while (fin.getline(key,KEY_LENGTH)){
		cout<<key<<endl;
		DoubleHashingProbe(hashTab, keyTab, key);
	}
	//cout<<hashTab[8]<<endl;
	//cout<<keyTab[8]<<endl;
	return 0;
}
	




