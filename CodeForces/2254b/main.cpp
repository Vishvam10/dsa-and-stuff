#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int res = 1;
	for (int i = 1; i < n; i++)
		res += (s[i] != s[i - 1]);

	int ans = res;

	for (int i = 1; i <= n - 2; i++) {
		if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
			ans = min(ans, res - 2);
		}

		else if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]) {
			ans = min(ans, res - 1);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
