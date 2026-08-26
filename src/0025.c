struct ListNode* reverseGroup(struct ListNode* head, struct ListNode* rest) {
    struct ListNode* prev = rest;
    struct ListNode* curr = head;

    while (curr != rest) {
        struct ListNode* temp = curr->next;

        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 1) {
        return head;
    }

    struct ListNode dummy = {0, head};
    struct ListNode* prev = &dummy;

    while (1) {
        struct ListNode* tail = prev;

        for (int i = 0; i < k; i++) {
            tail = tail->next;
            if (!tail) {
                return dummy.next;
            }
        }

        struct ListNode* rest = tail->next;
        struct ListNode* first = prev->next;

        prev->next = reverseGroup(first, rest);
        prev = first;
    }
}