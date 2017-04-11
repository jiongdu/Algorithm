ListNode* removeNthFromEnd(ListNode* head, int n){
	ListNode* start = new ListNode(0);
	start->next = head;
	ListNode* fast = start;
	int i=0;
	while(fast!=nullptr && i<n){
		fast = fast->next;
		i++;
	}
	ListNode* slow = start;
	while(fast->next!=nullptr){
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* temp = slow->next;
	slow->next = temp->next;
	delete temp;
	return start->next
}