#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;

const int kMaxSize = 26;

class TrieNode{
public:
    TrieNode():childrenSize_(0), terminableSize_(0){
        for(int i=0;i<kMaxSize;i++){
            children_[i]=nullptr;
        }
    }
    ~TrieNode(){
        for(int i=0;i<kMaxSize;i++){
            delete children_[i];
        }
    }
    void increChildrenSize(){
        if(childrenSize_>=26){
            return;
        }
        ++childrenSize_;
    }
    void increTerminableSize(){
        if(terminableSize_>=26){
            return;
        }
        ++terminableSize_;
    }
    void decreTerminableSize(){
        if(terminableSize_<=0){
            return;
        }
        --terminableSize_;
    }
    int getChildrenSize(){
        return childrenSize_;
    }
    int getTerminableSize(){
        return terminableSize_;
    }

    TrieNode* children_[kMaxSize];
private:
    int childrenSize_;
    int terminableSize_;
};

class Trie{
public:
    Trie() : root_(new TrieNode()){}

    void insert(string str){
        insert(str.c_str());
    }
    void insert(const char* str);

    bool find(string str){
        find(str.c_str());
    }
    bool find(const char* str);

    bool erase(string str){
        erase(str.c_str());
    }
    bool erase(const char* str);
    bool downNodeAlone();

    int getRedundantSize(TrieNode* trieNode);
    int getNoRedundantSize(TrieNode* trieNode);
    TrieNode* getHead(){
        return root_;
    }
private:
    TrieNode* root_;
};

void Trie::insert(const char* str){
    char* start = (char*)str;
    char* end = start + strlen(str);
    TrieNode* current = getHead();
    TrieNode* prev;
    for(; start!=end; start++){
        if(!current->children_[*start-'a']){
            current->children_[*start-'a']=new TrieNode();
            current->increChildrenSize();
        }
        prev = current;
        current = current->children_[*start-'a'];
    }
    prev->increTerminableSize();
}

bool Trie::find(const char* str){
    char* start = (char*)str;
    char* end = start + strlen(str);
    TrieNode* current = getHead();
    TrieNode* prev;
    for(; start!=end; start++){
        if(!current->children_[*start-'a']){
            return false;
            break;
        }
        prev = current;
        current = current->children_[*start-'a'];
    }
    if(prev->getTerminableSize()>0){
        return true;
    }
    return false;
}

bool Trie::erase(const char* str){
	if(find(str)){
		char* start = (char*)str;
		char* end = start + strlen(str);
		TrieNode* current = root_;
		TrieNode* prev;
		for(; start!=end;start++){
			if(downNodeAlone()){        //
				delete current;
				return true;
			}
			prev = current;
			current = current->children_[*start-'a'];
		}
		if(prev->getTerminableSize()>0){
			prev->decreTerminableSize();
		}
		return true;
	}
	return false;
}


bool Trie::downNodeAlone(){
    TrieNode* current = getHead();
	int terminableSum = 0;
	while(current->getChildrenSize()!=0){
		terminableSum += current->getTerminableSize();
		if(current->getChildrenSize()>1){
			return false;
		}else{              //current->ChildrenSize_ = 1
			for(int i=0;i<kMaxSize;i++){
				if(current->children_[i]){
					current = current->children_[i];
				}
			}
		}
	}
	if(terminableSum==1) return true;
	return false;
}

int Trie::getRedundantSize(TrieNode* trieNode){
    if(trieNode==nullptr) return 0;
    int res = trieNode->getTerminableSize();
    for(int i=0;i<kMaxSize;i++){
        res += getRedundantSize(trieNode->children_[i]);
    }
    return res;
}

int Trie::getNoRedundantSize(TrieNode* trieNode){
    if(trieNode==nullptr) return 0;
    int res = 0;
    if(trieNode->getTerminableSize()>0){
        res = 1;
    }
    if(trieNode->getChildrenSize()>0){
        for(int i=0l;i<kMaxSize;i++){
            res += getNoRedundantSize(trieNode->children_[i]);
        }
    }
    return res;
}

#endif // TRIE_H
