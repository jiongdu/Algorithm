#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <stdlib.h>
#include <algorithm>

const int kMaxHeight = 12;

/*
SkipListNode* getNodeMemory(int level){
	SkipListNode* node = (SkipListNode*)malloc(sizeof(SkipListNode)+level*sizeof(SkipListNode*));
	return node;
}
*/

class SkipListNode{
private:
	int key_;
	int value_;
public:
	SkipListNode* next_[1];
	SkipListNode(int key, int value) : key_(key), value_(value){}
	inline int getKey(){
		return key_;
	}
	inline int getValue(){
		return value_;
	}
};

class SkipList{
public:
	SkipList() : maxHeight_(1){
		head_ = createNode(maxHeight_, 0, 0);
		for(int i=0;i<maxHeight_; ++i){
			head_->next_[i] = nullptr;
		}
	}
	inline int getMaxHeight() const{
		return maxHeight_;
	}
	inline int randomHeight(){
		static const unsigned int k = 4;
		int height = 1;
		while(height < kMaxHeight && rand()%4==0){
			height++;
		}
		height = std::min(height, kMaxHeight);
		return height;
	}
	inline SkipListNode* getHead(){
		return head_;
	}
	int getLength(){
		int len = 0;
		SkipListNode* temp = head_;
		while(temp){
			len++;
			temp=temp->next_[0];
		}
		return len;
	}
	SkipListNode* createNode(int level, int key, int value);
	void insert(int key, int value);
private:
	int maxHeight_;
	SkipListNode* head_;
};

SkipListNode* SkipList::createNode(int level, int key, int value){
	char* mem = (char*)malloc(sizeof(SkipListNode)+level*sizeof(SkipListNode*));
	return new (mem) SkipListNode(key, value);
	/*
	SkipListNode* node = new SkipListNode();
	if(!node) return nullptr;
	return node;
	*/
}


SkipListNode* SkipList::findLessThan(const int& key, Node** prev){
	SkipListNode* x = head_;
	int level = getMaxHeight()-1;
	while(true){
		Node* next = x->next[level];
		if(next == nullptr || next->key >= key){
			if(level == 0){
				return x;
			}else{
				level--;
			}
		}else{
			x = next;
		}
	}
}

void SkipList::insert(int key, int value){
	SkipListNode* prev[kMaxHeight];
	SkipListNode* temp = nullptr;
	SkipListNode* p = head_;
	
	int i = getMaxHeight()-1;
	for(;i>=0;i--){
		while(temp = p->next_[i] && temp->getKey()<key){
			p = temp;
		}
		prev[i]=p;
	}
	
	int height = randomHeight();
	if(height>getMaxHeight()){
		for(int i=getMaxHeight();i<height;i++){
			prev[i]=head_;
		}
		maxHeight_ = height;
	}
	x = createNode(height, key, value);
	if(!x) return;
	for(int i=height-1;i>=0;i--){
		x->next[i] = prev[i]->next[i];
		prev[i]->next[i]=x;
	}
}


#endif