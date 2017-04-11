//第一种方法：两两合并
ListNode* mergeKLists(vector<ListNode*>& lists){
	int n = lists.size();
	if(n==0){
		return nullptr;
	}
	ListNode* res = lists[0];
	for(int i=1;i<n;++i){
		res = mergeTwoLists(res, lists[i]);
	}
	return res;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	if(l1==nullptr || l2==nullptr){
		return (l1==nullptr)?l2:l1;
	}
	ListNode dummy(0);
	ListNode* p = &dummy;
	while(l1!=nullptr && l2!=nullptr){
		if(l1->val <= l2->val){
			p->next = l1;
			l1 = l1->next;
		}else{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	p->next = ((l1==nullptr)?l2:l1);
}