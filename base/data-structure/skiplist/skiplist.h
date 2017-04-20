#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <stdlib.h>
#include <algorithm>

const int kMaxHeight = 8;

class SkipListNode{
private:
	int key_;
	int value_;
public:
	SkipListNode* next_[1];
	SkipListNode(int key=0, int value=0) : key_(key), value_(value){}
	inline int getKey(){
		return key_;
	}
	inline int getValue(){
		return value_;
	}
	inline void setValue(int value){
		value_ = value;
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
	inline void setMaxHeight(int height){
        maxHeight_ = height;
	}

	inline int randomHeight(){
		int height = 1;
		while(rand()%2){
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
	bool insert(int key, int value);
	bool erase(int key);
	int search(int key);
	void decreMaxHeight(){
		maxHeight_--;
	}
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

bool SkipList::insert(int key, int value){
	SkipListNode* prev[kMaxHeight];
	SkipListNode* temp = nullptr;
	SkipListNode* p = head_;

	int i = getMaxHeight()-1;
	for(;i>=0;i--){
        temp = p->next_[i];
		//while((temp = p->next_[i]) && (temp->getKey()<key)){
		while(temp = p->next_[i]){
            if(temp->getKey()<key){
                p = temp;
            }
		}
			//p = temp;
		//}
		prev[i]=p;
	}
	if(temp && temp->getKey()==key){
		temp->setValue(value);
		return true;
	}

	int height = randomHeight();
	if(height>getMaxHeight()){
		for(int i=getMaxHeight();i<height;i++){
			prev[i]=head_;
		}
		setMaxHeight(height);
	}
	SkipListNode* x = createNode(height, key, value);
	if(!x) return false;
	for(int i=height-1;i>=0;i--){
		x->next_[i] = prev[i]->next_[i];
		prev[i]->next_[i]=x;
	}
	return true;
}

bool SkipList::erase(int key){
	SkipListNode* prev[kMaxHeight]={nullptr};
	SkipListNode* temp = nullptr;
	SkipListNode* p = head_;

	int i = getMaxHeight()-1;
	for(;i>=0;i--){
		while((temp = p->next_[i]) && (temp->getKey()<key)){
			p = temp;
		}
		prev[i]=p;
	}

	if((!temp) || (temp && temp->getKey()==key)){
		return false;
	}
	for(int i=getMaxHeight()-1; i>=0; --i){
		if(prev[i]->next_[i]==temp){
			prev[i]->next_[i]=temp->next_[i];
			if(head_->next_[i]==nullptr){
				decreMaxHeight();
			}
		}
	}
	free(p);
	temp = nullptr;
	return true;
}

int SkipList::search(int key){
	SkipListNode* temp = nullptr;
	SkipListNode* p = head_;

	int i=getMaxHeight()-1;
	for(;i>=0;--i){
		while(((temp = p->next_[i])!=nullptr)&&(temp->getKey()<key)){
			p = temp;
		}
		if((temp) && (key==temp->getKey())){
			return temp->getValue();
		}
	}
	return -1;
}


#endif
