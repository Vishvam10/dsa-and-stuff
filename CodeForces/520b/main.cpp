#include <iostream> // for cin, cout

using namespace std;

// With standard BFS
// void solve() {
//     double n, m;
//     cin >> n >> m;
//     // 10 --> 5 : - - - -
//     if(m < n) {
//         cout << (n - m) << "\n";
//         return;
//     }
//     // 5 --> 12 : 5 * ceil(12/5) - 12 = 3 ... but here
//     // 4 --> 6 : optimal way is 4 (-1) --> 3 (* 2) --> 6

//     // At any point, we can do (x - 1) or (2 * x). BFS ?
//     queue<pair<int, int>> q;
//     vector<bool> vis(2 * m + 1, false);

//     q.push({n, 0});
//     vis[n] = true;

//     while(!q.empty()) {
//         auto [num, depth] = q.front();
//         q.pop();

//         vis[num] = true;

//         if(num == m) {
//             cout << depth << "\n";
//             return;
//         }

//         if(num - 1 > 0 && !vis[num - 1]) {
//             q.push({num - 1, depth + 1});
//         }
//         if(2 * num <= 2 * m && !vis[2 * num]) {
//             q.push({2 * num, depth + 1});
//         }
//     }
// }

// With a bit of thinking
void solve() {
	int n, m;
	cin >> n >> m;

	if (n >= m) {
		cout << n - m << '\n';
		return;
	}

	int ans = 0;

	while (m > n) {
		if (m % 2 == 0)
			m /= 2;
		else
			m++;
		ans++;
	}

	// We've gone below n, so only +1 operations are needed.
	ans += (n - m);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
