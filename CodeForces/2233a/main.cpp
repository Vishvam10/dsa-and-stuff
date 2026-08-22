#include <algorithm> // for max, min, sort, etc.
#include <cmath>     // for sqrt, round
#include <iostream>  // for cin, cout

using namespace std;
using ll = long long int;

void solve() {
	ll n, x, y, z;
	cin >> n >> x >> y >> z;

	ll withoutZ = ceil(n / (x + y));
	ll withZ;
	if (x * z >= n) {
		withZ = ceil(n / x);
	} else {
		ll rem = n - x * z;
		withZ = z + ceil(rem / (x + (10 * y)));
	}

	cout << min(withZ, withoutZ) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
