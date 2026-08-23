struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }

    while (listsSize > 1) {
        int pos = 0;

        for (int i = 0; i < listsSize; i += 2) {
            if (i + 1 < listsSize) {
                lists[pos++] = mergeTwoLists(lists[i], lists[i + 1]);
            } else {
                lists[pos++] = lists[i];
            }
        }
        listsSize = pos;
    }

    return lists[0];
}