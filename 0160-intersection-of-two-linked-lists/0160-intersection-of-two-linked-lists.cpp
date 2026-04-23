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
            if (listA == nullptr) {
                listA = headB;
            } else {
                listA = listA->next;
            }
            if (listB == nullptr) {
                listB = headA;
            } else {
                listB = listB->next;
            }
        }
        return listB;
    }
};