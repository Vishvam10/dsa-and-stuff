#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	if (n == 1) {
		cout << 0 << "\n";
	} else if (n == 2) {
		cout << s << "\n";
	} else {
		cout << 2 * s << "\n";
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
