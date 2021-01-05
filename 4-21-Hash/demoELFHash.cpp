#include <iostream>
#include "ELFHash.h"
using namespace std;

int main(){
	char key[] = "Quand je passe devant le champs de fleur, je n'ai pas envie de tourner ma tete";
	int h = ELFHashDemo(key);
	cout << "Hash (" << key << ") = " << h << endl;

	return 0;
}
	

