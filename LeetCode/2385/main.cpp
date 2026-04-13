class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_map<TreeNode*, bool> infection;
    TreeNode* startNode;

    void markParents(TreeNode *node, int start) {
        if (!node) return;

        if (node->val == start) startNode = node;

        if (node->left) {
            mp[node->left] = node;
            markParents(node->left, start);
        }
        if (node->right) {
            mp[node->right] = node;
            markParents(node->right, start);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        markParents(root, start);

        queue<TreeNode*> q;
        q.push(startNode);
        infection[startNode] = true;

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && !infection[node->left]) {
                    q.push(node->left);
                    infection[node->left] = true;
                    spread = true;
                }

                if (node->right && !infection[node->right]) {
                    q.push(node->right);
                    infection[node->right] = true;
                    spread = true;
                }

                if (mp[node] && !infection[mp[node]]) {
                    q.push(mp[node]);
                    infection[mp[node]] = true;
                    spread = true;
                }
            }

            if (spread) ans++;
        }

        return ans;
    }
};