#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int mx = *max_element(arr.begin(), arr.end());
	int mn = *min_element(arr.begin(), arr.end());
	int mxi = -1, mni = -1;
	for (int i = 0; i < n; i++) {
		if (mxi == -1 && arr[i] == mx)
			mxi = i;
		if (arr[i] == mn)
			mni = i;
	}
	int ans = mxi - 1 + n - mni;
	cout << ((mxi > mni) ? ans - 1 : ans) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
