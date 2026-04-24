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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        int removal = size - n + 1;
        if (removal == 1) {
            ListNode* newHead = head->next;
            delete head; // Optional: free memory
            return newHead;
        }
        ListNode* tempB = head;
        int a = 1;
        while (a < (removal - 1)) {
            a++;
            tempB = tempB->next;
        }

        ListNode* nodeToRemove = tempB->next;

        // Skip the target node
         if (nodeToRemove != nullptr) {
        tempB->next = nodeToRemove->next;

        // Optional: clean up
        delete nodeToRemove;
         }
        return head;
    }
};