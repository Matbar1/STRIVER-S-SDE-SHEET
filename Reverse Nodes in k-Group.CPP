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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (head == nullptr || head->next == nullptr || k == 1) {
        return head;
    }

    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* pre = dummyHead;
    ListNode* nextNode = nullptr;

    while (length >= k) {
        curr = pre->next;
        nextNode = curr->next;

        for (int i = 1; i < k; i++) {
            curr->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
            nextNode = curr->next;
        }

        pre = curr;
        length -= k;
    }

    return dummyHead->next;
}

        
    
};