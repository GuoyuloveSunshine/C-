#include <iostream>
#include "ELFHash.h"
using namespace std;

int main(){
	char key[200];
	static int hashTab[HASH_M+1];
	while (cin.getline(key,200)){
		int h = ELFHash(key);
		if (0==hashTab[h])
			cout << "Hash (" << key << ") = " << h << endl;
		else	cout << "Key (" << key << ") is encountered again\n";
		hashTab[h]++;
	}
	return 0;
}
	

