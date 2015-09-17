int ListLength(struct ListNode* head){
	int cnt;
	for (cnt = 0; head; head = head->next, cnt++);
	return cnt;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
	if (!head)   return NULL;
	int len = ListLength(head);
	if (!(k %= len))   return head;
	struct ListNode *fast, *tmp;
	for (k = len - k - 1, fast = head; k--; fast = fast->next);
	for (tmp = fast->next, fast->next = NULL, fast = tmp; fast->next; fast = fast->next);
	fast->next = head;
	return tmp;
}