struct ListNode* recur(struct ListNode* current,struct ListNode* pre){
    if(!current)    return pre;
    struct ListNode* res = recur(current->next, current);
    current->next=pre;
    return res;
} 
 
struct ListNode* reverseList(struct ListNode* head) {
    return recur(head, NULL);
}