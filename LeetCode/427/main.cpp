/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* solve(
        int rStart, int rEnd, int colStart, int colEnd, vector<vector<int>>& mat
    ) {
        int val = mat[rStart][colStart];
        bool good = true;

        for (int i = rStart; i < rEnd; ++i) {
            for (int j = colStart; j < colEnd; ++j) {
                if (mat[i][j] != val) {
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }

        if (good) {
            return new Node(val, true);
        }

        int rMid = (rStart + rEnd) / 2;
        int cMid = (colStart + colEnd) / 2;

        Node* node = new Node(1, false);

        node->topLeft = solve(rStart, rMid, colStart, cMid, mat);
        node->topRight = solve(rStart, rMid, cMid, colEnd, mat);
        node->bottomLeft = solve(rMid, rEnd, colStart, cMid, mat);
        node->bottomRight = solve(rMid, rEnd, cMid, colEnd, mat);

        return node;
    }


    Node* construct(vector<vector<int>>& mat) {
        int n = mat.size();
        Node *root = solve(0, n, 0, n, mat);
        return root;
    }
};