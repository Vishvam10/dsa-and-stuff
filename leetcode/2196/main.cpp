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
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        // mp : node val -> node and c : child freq
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> c;
        for (auto& v : arr) {
            auto p = mp[v[0]] ? mp[v[0]] : mp[v[0]] = new TreeNode(v[0]);
            auto q = mp[v[1]] ? mp[v[1]] : mp[v[1]] = new TreeNode(v[1]);
            (v[2] ? p->left : p->right) = q;
            c.insert(v[1]);
        }
        for (auto [val, node] : mp) if (!c.count(val)) return node;
        return nullptr;
    }
};
