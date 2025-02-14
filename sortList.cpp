class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;      
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);
        return merge(leftSorted, rightSorted);
    }
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
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
};
