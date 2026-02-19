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
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});

        while(!q.empty()) {

            TreeNode *node = q.front();
            int sz = q.size();
            q.pop();
            vector<int> layer;

            for(int i = 0; i < sz; ++i) {
                if(node->left != nullptr) {
                    q.push(node->left);
                    layer.push_back(node->left->val);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                    layer.push_back(node->right->val);
                }
            }

            if(layer.size() > 0) {
                ans.push_back(layer);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


























