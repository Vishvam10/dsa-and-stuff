#include <iostream> // for cin, cout

using namespace std;
using ll = long long int;

void solve() {
	ll l, r;
	cin >> l >> r;
	ll cnt = 1, start = l;
	for (int i = 1; i <= r - l + 1; ++i) {
		start += i;
		if (start > r)
			break;
		cnt++;
	}
	cout << cnt << "\n";
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
