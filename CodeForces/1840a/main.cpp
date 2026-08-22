#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s, ans;
	cin >> s;

	int i = 0;
	while (i < n) {
		ans += s[i];
		int j = i + 1;
		while (j < n && s[j] != s[i])
			j++;
		i = j + 1;
	}

	cout << ans << '\n';
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
