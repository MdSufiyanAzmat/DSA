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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        
        while (listA != listB) {
            // Move to next, or if at end, switch to the other list's head
            listA = (listA == nullptr) ? headB : listA->next;
            listB = (listB == nullptr) ? headA : listB->next;
        }
        
        return listA; // Works for both intersection node or nullptr
    }
};