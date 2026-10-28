class Solution {
private:
    int nRows = 0, nCols = 0;
    vector<vector<vector<int>>> dp;

    int dfs(int x, int y, int curXor, vector<vector<int>>& mat){
        if(x >= nRows || y >= nCols) return INT_MAX;
        curXor ^= mat[x][y];
        if(x == nRows - 1 && y == nCols - 1) return curXor;
        if(dp[x][y][curXor] != -1) return dp[x][y][curXor];
        int right = dfs(x + 1, y, curXor, mat);
        int down = dfs(x, y + 1, curXor, mat);
        return dp[x][y][curXor] = min(right, down);
    }
public:
    int minCost(vector<vector<int>>& mat) {
        nRows = mat.size(), nCols = mat[0].size();
        dp = vector<vector<vector<int>>>(nRows, vector<vector<int>>(nCols, vector<int>(1024, -1)));
        return dfs(0, 0, 0, mat);
    }
};
