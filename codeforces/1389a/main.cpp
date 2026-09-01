#include <cassert>
#include <iostream>

using namespace std;
using ll = long long int;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

void solve() {
	int l, r;
	cin >> l >> r;

	if (2 * l > r)
		cout << -1 << " " << -1 << "\n";
	else
		cout << l << " " << 2 * l << "\n";
	return;
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
