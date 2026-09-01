#include <cassert>
#include <iostream>

using namespace std;

void solve() {
	int nRows, nCols;
	cin >> nRows >> nCols;

	if (nRows % 2 == 0 || nCols % 2 == 0) {
		cout << nRows * nCols / 2 << "\n";
	} else {
		int square = nCols * ((nRows - 1) / 2);
		int strip = ((nCols + 1) / 2);
		cout << square + strip << "\n";
	}
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
