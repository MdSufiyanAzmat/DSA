/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
     int ans = 0;
     int maxAns = INT_MIN;
     queue<pair<TreeNode*, unsigned long long>> q;
     q.push({root, 0});
     while(!q.empty()){
        int s =  q.size();
        unsigned long long st = q.front().second;
        unsigned long long end = q.back().second;
        maxAns = max(maxAns, (int)(end - st) + 1);
        for(int i=0; i<s; i++){
            auto node = q.front();
            q.pop();
            if(node.first->left) q.push({node.first->left, node.second*2+1});
            if(node.first->right) q.push({node.first->right, node.second*2+2});
        }
     }
     return maxAns;
    }
};