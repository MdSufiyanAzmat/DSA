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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
       unordered_map<int, TreeNode*> mp;
       unordered_set<int> children;
       for(auto &d : desc){
        int p = d[0];
        int c = d[1];
        int isLeft = d[2];
        if(mp.find(p) == mp.end()){
            mp[p] = new TreeNode(p);
        }
        if(mp.find(c) == mp.end()){
            mp[c] = new TreeNode(c);
        }
        if(isLeft == 1){
            mp[p] -> left = mp[c];
        }else{
            mp[p] -> right = mp[c];
        }
        children.insert(c);
       } 
       for(auto &a : mp){
        if(children.find(a.first) == children.end()){
            return a.second;
        }
       }
    return nullptr;
    }
};