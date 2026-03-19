class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& mat) {
        int nRows = mat.size(), nCols = mat[0].size();
        int ans = 0;

        vector<int> rowPre(nCols, 0), colPre(nCols, 0);

        for(int i = 0; i < nRows; ++i) {
            int rs = 0, cs = 0;
            for(int j = 0; j < nCols; ++j) {
                if(mat[i][j] == 'X') rs++;
                else if (mat[i][j] == 'Y') cs++;
                rowPre[j] += rs; colPre[j] += cs;
                if(rowPre[j] > 0 && rowPre[j] == colPre[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};