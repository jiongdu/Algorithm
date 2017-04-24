/*
空间代价：
--O(n+r)
时间复杂度：
--O(d*(n+r))
--不需要移动记录本身，只需要修改记录的next指针
稳定排序
*/


typedef struct Node{
	int key;
	int next;	//下一个节点在数组中的下标
}Node;

typedef struct StaticQueue{
	int head;
	int tail;
}StaticQueue;

void Distribute(vector<Node>& node, int first, int i, int r, StaticQueue* queue);
void Collect(vector<Node>& node, int& first, int r, StaticQueue* queue);

void RadixSort(vector<int>& nums, int d, int r){
	int i, first=0;
	int n=nums.size();
	vector<Node> node(n);
	StaticQueue* queue = new StaticQueue[r];
	for(i=0;i<n-1;i++){
		node[i].key=nums[i];
		node[i].next=i+1;
	}
	node[n-1].key=nums[n-1];
	node[n-1].next=-1;
	
	for(i=0;i<d;i++){			//d趟的分配和收集
		Distribute(node, first, i, r, queue);			//分配到不同队列
		Collect(node, first, r, queue);					//聚合
	}
	for(i=0;i<r;i++){
		if(queue[i].head==-1) continue;
		else break;
	}
	
	int j=queue[i].head;
	while(node[j].next!=-1){		//排序结果
		cout << node[j].key << endl;
		j = node[j].next;
	}
	cout << node[j].key << endl;
	
	delete[] queue;
}

void Distribute(vector<Node>& node, int first, int i, int r, StaticQueue* queue){
	int current=first;
	for(int j=0;j<r;j++){
		queue[j].head=-1;
	}
	while(current!=-1){
		int k = node[current].key;
		for(int a=0;a<i;a++){
			k=k/r;
		}
		k=k%r;
		if(queue[k].head==-1){
			queue[k].head=current;
		}else{
			node[queue[k].tail].next=current;
		}
		queue[k].tail=current;
		current=node[current].next;
	}
}

void Collect(vector<Node>& node, int& first, int r, StaticQueue* queue){
	int last,k=0;
	while(queue[k].head==-1) k++;
	first=queue[k].head;
	last=queue[k].tail;
	while(k<r-1){
		k++;
		while(k<r-1 && queue[k].head==-1){
			k++;
		}
		if(queue[k].head!=-1){
			node[last].next=queue[k].head;
			last=queue[k].tail;
		}
	}
	node[last].next=-1;
}



