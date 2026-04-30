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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist = new ListNode(0, nullptr);
        ListNode* blist = new ListNode(0, nullptr);
        ListNode* small = slist;
        ListNode* big = blist;
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp -> val < x){
                small -> next = temp;
                small = small -> next;
            }else{
                big -> next = temp;
                big = big -> next;
            }
            temp = temp -> next;
        }
        small -> next = blist -> next;
        big -> next = nullptr;
        ListNode* result = slist -> next;
        delete slist;
        delete blist;
        return result;
    }
};