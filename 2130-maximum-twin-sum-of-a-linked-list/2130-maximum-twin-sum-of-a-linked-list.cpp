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
    int pairSum(ListNode* head) {
       int ans = 0;
       int maxAns = INT_MIN;
       vector<int> v;
       while(head != nullptr){
        v.push_back(head->val);
        head = head -> next;
       }
       int n = v.size();
       for(int i=0; i<(n/2); i++){
        ans = v[i] + v[n-i-1];
        maxAns = max(maxAns, ans);
       }
       return maxAns;
    }
};