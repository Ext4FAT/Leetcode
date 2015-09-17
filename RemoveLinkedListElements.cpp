ListNode* removeElements(ListNode* head, int val) {
	if(!head)  return NULL;    
	ListNode *h, *pre, *node;
	for (h = pre = new ListNode(-1), h->next = head; node = pre->next; ) 
		if (node->val == val) 
			pre->next = node->next;
		else
			pre = pre->next;
	return h->next;
}