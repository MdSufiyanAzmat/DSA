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

ListNode* reverse(ListNode* head){

        ListNode* curr = head;
        ListNode* newHead = NULL;
      while(curr != NULL){
        ListNode* newNode = new ListNode(curr-> val);
        newNode-> next = newHead;
        newHead = newNode;
        curr = curr -> next;
      }
      return newHead;
}
    int pairSum(ListNode* head) {
       ListNode* dummy = reverse(head);
       ListNode* temp = head;
       int n = 0;
       while(temp != NULL){
        temp = temp -> next;
        n++;
       }
       int a = 0;
       int ans = 0;
       int maxi = INT_MIN;
       while(a < n / 2){
        ans = head -> val + dummy -> val;
        head = head -> next;
        dummy = dummy -> next;
        maxi = max(ans, maxi);
        a++;
       }
       return maxi;
    }
};