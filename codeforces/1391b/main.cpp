#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int nRows, nCols, ans = 0;
	cin >> nRows >> nCols;
	vector<vector<char>> mat(nRows, vector<char>(nCols));
	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nCols; ++j) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < nCols; ++i) {
		ans += (mat[nRows - 1][i] == 'D');
	}
	for (int i = 0; i < nRows; ++i) {
		ans += (mat[i][nCols - 1] == 'R');
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
