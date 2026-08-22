#include <iostream> // for cin, cout

using namespace std;

using ull = unsigned long long int;
const ull MOD = 998244353;

ull modPow(ull base, ull exp, ull mod) {
	ull ans = 1 % mod;
	base %= mod;

	while (exp) {
		if (exp & 1)
			ans = (ull)ans * base % mod;
		base = (ull)base * base % mod;
		exp >>= 1;
	}

	return ans;
}

void solve() {
	ull n, m, r, c;
	cin >> n >> m >> r >> c;
	ull exponent = n * m - (n - r + 1) * (m - c + 1);
	cout << (ull)modPow(2, exponent, MOD) << "\n";
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
