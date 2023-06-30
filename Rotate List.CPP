class Solution {
public:
     int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next) ++ans;
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;
        auto p = head, q = head;
        while (k--) q = q->next;
        while (q->next) p = p->next, q = q->next;
        auto ans = p->next;
        p->next = nullptr;
        q->next = head;
        return ans;
    }
};