/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        
        // Traverse both lists until they intersect or reach the end
        while (pA != pB) {
            // If we reach the end of list A, move to the head of list B
            if (pA == nullptr)
                pA = headB;
            else
                pA = pA->next;
            
            // If we reach the end of list B, move to the head of list A
            if (pB == nullptr)
                pB = headA;
            else
                pB = pB->next;
        }
        
        return pA; // or pB, they both point to the intersection or nullptr
    }
};