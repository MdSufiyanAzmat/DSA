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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
     ListNode* dummy = new ListNode(0, nullptr);
     ListNode* current = dummy;
      while(h1 != nullptr && h2 != nullptr){
        if(h1 -> val > h2 -> val){
            current -> next = h2;
            h2 = h2 -> next;
        }else{
            current -> next = h1;
            h1 = h1 -> next;
        }
        current = current -> next;
      }
      if(h1 != nullptr){
        current -> next = h1;
      }
      if(h2 != nullptr){
        current -> next = h2;
      }
      ListNode* res = dummy -> next;
      return res;
    }
};