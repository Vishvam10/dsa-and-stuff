#include <iostream> // for cin, cout
#include <string>   // for string operations
#include <unordered_map>

using namespace std;

void solve() {
	int k;
	cin >> k;
	string s;
	cin >> s;

	unordered_map<char, int> mp;

	for (char c : s)
		mp[c]++;
	for (auto [c, f] : mp) {
		if (f % k != 0) {
			cout << -1 << '\n';
			return;
		}
	}

	string pre, ans;

	for (auto [c, f] : mp)
		pre += string(f / k, c);
	for (int i = 0; i < k; i++)
		ans += pre;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
