/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
 int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, ++len);
        return len;
    }
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int len = (getLength(head) + 1) / 2;
        ListNode *p = head, *q;
        while (--len > 0) p = p->next;
        q = p->next;
        p->next = NULL;
        q = reverse(q);
        while (head && q) {
            if (head->val != q->val) return false;
            head = head->next;
            q = q->next;
        }
        return true;
    }
};