class Solution {
  public:
	void moveToEnd(int n, vector<char>& arr) {
		int right = n - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (arr[i] == '*') {
				right = i - 1;
			} else if (arr[i] == '#') {
				swap(arr[i], arr[right]);
				right--;
			}
		}
	}

	vector<vector<char>> rotateTheBox(vector<vector<char>>& mat) {
		int nRows = mat.size(), nCols = mat[0].size();
		vector<vector<char>> ans(nCols, vector<char>(nRows, '.'));
		for (int i = 0; i < nRows; ++i)
			moveToEnd(nCols, mat[i]);
		for (int i = 0; i < nRows; ++i) {
			for (int j = 0; j < nCols; ++j) {
				ans[j][nRows - i - 1] = mat[i][j];
			}
		}
		return ans;
	}
};