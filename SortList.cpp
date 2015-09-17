#define MYNEXT(_TMP,_HEAD)    \
		_TMP->next=_HEAD;     \
		_TMP=_HEAD;           \
		_HEAD=_HEAD->next;    

ListNode* mergeList(ListNode* h1, ListNode* h2){
	ListNode *head, *tmp;
	for(tmp = head = new ListNode(0);h1 && h2;)
		if(h1->val < h2->val){
			MYNEXT(tmp,h1)
		}
		else{
			MYNEXT(tmp,h2)
		}
	if(h1)  tmp->next = h1;
	else  tmp->next = h2;
	return head->next;
}

ListNode* sortList(ListNode* head) {
	if(!head||!head->next)  return head;
	//find the middle;
	ListNode *slow, *fast;
	for(slow = fast = head; fast->next && fast->next->next; slow = slow->next, fast = fast->next->next) ;
	fast = slow->next;
	slow->next = NULL;
	//recur sort the list
	slow = sortList(head);
	fast = sortList(fast);
	//merge two sorted list
	return mergeList(slow,fast);
}