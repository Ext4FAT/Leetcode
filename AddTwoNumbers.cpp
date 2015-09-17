ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1)    return l2;
	if (!l2)    return l1;   
	int forward, x;
	ListNode *l;
	for (l = new ListNode(-1), l->next = l1, l1 = l, forward = 0; l1->next && l2; l1 = l1->next, l2 = l2->next){
		x = l1->next->val + l2->val + forward;
		forward = x < 10? 0: 1;
		l1->next->val = x < 10? x: x - 10;
	}
	for (l1->next = l1->next? l1->next: l2; forward;){
		if (!l1->next) l1->next = new ListNode(0);
		l1 = l1->next;
		x = l1->val + forward;
		forward = x < 10? 0: 1;
		l1->val = x < 10? x: x - 10;
	}
	return l->next;
}