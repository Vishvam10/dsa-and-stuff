class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> layer;

            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();

                layer.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(layer);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
