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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr) return head;
        vector<int> vec;
        ListNode* temp = head;
        while (temp != nullptr) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int n = vec.size();
        k = k % n;
         if (k == 0) return head;
        ListNode* newHead = new ListNode(vec[n-k]);
        ListNode* newTemp = newHead;
        for (int i = n - k + 1; i < n; i++) {
            newTemp->next = new ListNode(vec[i]);
            newTemp = newTemp->next;
        }
        for (int i = 0; i <n- k; i++) {
            newTemp->next = new ListNode(vec[i]);
            newTemp = newTemp->next;
        }
        return newHead;
    }
};