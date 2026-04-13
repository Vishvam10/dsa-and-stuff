/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_map<TreeNode*, bool> vis;
    TreeNode* startNode;

    void markParents(TreeNode* node, TreeNode* target) {
        if (!node) return;
        if (node == target) startNode = node;

        if (node->left) {
            mp[node->left] = node;
            markParents(node->left, target);
        }
        if (node->right) {
            mp[node->right] = node;
            markParents(node->right, target);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root, target);
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = true;
        while (!q.empty()) {
            int size = q.size();

            if (k == 0) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }

                if (mp[node] && !vis[mp[node]]) {
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                }
            }

            k--;
        }
        return ans;
    }
};