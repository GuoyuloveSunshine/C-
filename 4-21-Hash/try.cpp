#include <iostream>
#include <bitset>
using namespace std;

#define HASH_M 0x7FFF
int ELFHashDemo(int key[]){
	unsigned long h = 0;
	while (*key){
		std::cout << "+" << *key <<"(" << std::bitset<8>(*key) << ") | h: " << std::bitset<32>(h) << " => ";
		h = (h<<4) + *key++;
		std::cout << std::bitset<32>(h) << " | ";
		unsigned long g = h & 0xF0000000L;
		if (g){ 
			std::cout << "g = " << std::bitset<32>(g) << "  ";
			h ^= g >> 24;
			std::cout << "h:" << std::bitset<32>(h) << " | ";
		}
		h &= ~g;
		std::cout << "h = " << std::bitset<32>(h) << std::endl;
	}
	return h % HASH_M;  // second way: h & HASH_M
}


int main(){
	char key[] = "Quand je passe devant le champs de fleur, je n'ai pas envie de tourner ma tete";
    int key2[]={14989450,15041973, 14990480, 15249547, 15711372, 15041974, 15117473, 14990480, 14989988, 15711372, 15041974, 15117473, 14990480, 15041973};
	int h = ELFHashDemo(key2);
	cout << "Hash (" << key2 << ") = " << h << endl;

	return 0;
}