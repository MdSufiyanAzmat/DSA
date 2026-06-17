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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        while(!q.empty()){
            vector<int> curr;   
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
                curr.push_back(node -> val);
            }
            ans.push_back(curr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};