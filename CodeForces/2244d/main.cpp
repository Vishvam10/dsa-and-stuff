#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <cstddef>
#include <iostream> // for cin, cout
#include <utility>
#include <vector> // for vector

using namespace std;

int sum(int n, vector<int>& prod, pair<int, int> p) {
	if (p.first == 0 && p.second == 0)
		return INT_MIN;
	int low = min(n, p.first), high = max(n, p.second), ans = 0;
	for (int i = low + 1; i < high; ++i)
		ans += (prod[i] * -1);
	cout << "ans : " << ans << "\n";
	return ans;
}

void assign(pair<int, int>& p, int val) {
	if (val > p.first && val > p.second) {
		p.first = p.second;
		p.second = val;
	} else if (val > p.first && val < p.second) {
		p.first = val;
	}
}

int check(int i, vector<int> prod, vector<int>& posts, pair<int, int> el,
          vector<int>& dp) {
	cout << "i, el : " << i << ", " << el.first << ", " << el.second << "\n";
	if (dp[i] != -1)
		return dp[i];
	pair<int, int> temp = el;
	assign(el, posts[i]);
	int pick = sum(prod.size(), prod, el) + check(i + 1, prod, posts, el, dp);
	int dont = check(i + 1, prod, posts, temp, dp);
	return dp[i] = max(pick, dont);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> prod(n), posts(m);
	for (int i = 0; i < n; ++i)
		cin >> prod[i];
	for (int i = 0; i < m; ++i)
		cin >> posts[i];

	vector<int> dp(n + 1, -1);
	pair<int, int> el = {0, 0};
	check(0, prod, posts, el, dp);

	cout << "\nDP : \n";
	for (int i = 0; i < n; ++i) {
		cout << dp[i] << ", ";
	}
	cout << "\n";

	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";

	// 15 AND 7 AND 12 =>
	// [1, 7] := [1, 12] := [1, 15]
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	// -------------
	// --------------------------
	// ----------------------------------
	// => Flip numbers from [(2nd max + 1), max]
	// 15 AND 6 AND 2 AND 12
	// [1, 2] := [1, 6] := [1, 12] := [1, 15] => No change
	//
	// -1 2 -3 4 -5 and 1 5 3
	// ideal : 1 2 3 4 5
	// 5 AND 3 = no effect on 1 2 3, 4 and 5 are flipped
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
