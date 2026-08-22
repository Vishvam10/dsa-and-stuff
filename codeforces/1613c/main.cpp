#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;
using ll = long long int;

void solve() {
	ll n, h;
	cin >> n >> h;
	vector<ll> arr(n);
	for (ll i = 0; i < n; ++i)
		cin >> arr[i];

	auto f = [&](ll k) {
		// Counting the effect of last attack here instead
		// of doing cnt += k at the end
		ll cnt = k;
		for (ll i = 0; i < n - 1; ++i) {
			ll start = arr[i], end = arr[i + 1];
			cnt += min(k, end - start);
			if (cnt >= h)
				return true;
		}
		return cnt >= h;
	};

	ll low = 1, high = h, ans = 0;
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		if (f(mid)) {
			high = mid - 1;
			ans = mid;
		} else {
			low = mid + 1;
		}
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
