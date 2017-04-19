#include "Trie.h"
#include <iostream>

int main(){
	Trie trie;
	trie.insert("hello");
	trie.insert("how");
	trie.insert("hello");
	trie.insert("haha");

    const char* test1 = "hello";
    const char* test2 = "haha";
	std::cout << trie.getRedundantSize(trie.getHead()) << std::endl;
	std::cout << trie.getNoRedundantSize(trie.getHead()) << std::endl;
	std::cout << trie.find(test1) << std::endl;

	if(!trie.erase(test2)){
        std::cout << "erase error!" << std::endl;
	}

	std::cout << trie.getRedundantSize(trie.getHead()) << std::endl;
	std::cout << trie.getNoRedundantSize(trie.getHead()) << std::endl;
	std::cout << trie.find(test1) << std::endl;
}
