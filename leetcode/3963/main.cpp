class Solution {
public:
    vector<string> createGrid(int nRows, int nCols) {
        vector<string> ans(nRows, string(nCols, '#'));
        for(int i = 0; i < nCols; ++i) ans[0][i] = '.';
        for(int i = 0; i < nRows; ++i) ans[i][nCols - 1] = '.';
        return ans;
    }
};
