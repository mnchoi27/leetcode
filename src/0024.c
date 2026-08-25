struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy = {0, head};
    struct ListNode* prev = &dummy;
    struct ListNode* curr = prev->next;

    while (curr && curr->next) {
        struct ListNode* temp = curr->next;

        curr->next = temp->next;
        prev->next = temp;
        temp->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return dummy.next;
}