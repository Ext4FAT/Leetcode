void deleteNode(ListNode* node) {
	if(node && node->next){
		node->val = node->next->val; 
		node->next = node->next->next;
	}
}