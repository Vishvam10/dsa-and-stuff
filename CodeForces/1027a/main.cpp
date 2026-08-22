#include <cmath>    // for sqrt, round
#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n / 2; ++i) {
		int diff = abs(s[i] - s[n - i - 1]);
		if (diff == 1 || diff > 2) {
			cout << "NO" << "\n";
			return;
		}
	}

	cout << "YES" << "\n";
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
