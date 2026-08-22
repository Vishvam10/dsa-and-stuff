#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n;
	cin >> n;
	bool ans = false;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (val == 100)
			ans = true;
	}

	cout << (ans ? "Yes" : "No") << "\n";
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
