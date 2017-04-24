#include "skiplist.h"

#include <iostream>

int main(){
	SkipList skipList;

	skipList.insert(1,1);
	skipList.insert(2,2);
	skipList.insert(3,3);
    skipList.insert(4,4);
    skipList.insert(5,5);

    std::cout << skipList.getLength() << std::endl;
	std::cout << skipList.search(1) << std::endl;
	std::cout << skipList.search(2) << std::endl;

	std::cout << skipList.search(6) << std::endl;

	if(skipList.erase(4)==false){
        std::cout << "skiplist erase error" << std::endl;
	}
	std::cout << skipList.search(4) << std::endl;

	std::cout << skipList.getLength() << std::endl;


	return 0;
}
