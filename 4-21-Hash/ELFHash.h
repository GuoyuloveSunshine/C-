#include <iostream>
#include <bitset>

#define HASH_M 0x7FFF

int ELFHash(char* key){
	unsigned long h = 0;
	while (*key){
		h = (h<<4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % HASH_M;  // second way: h & HASH_M
}

int ELFHashDemo(char* key){
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



