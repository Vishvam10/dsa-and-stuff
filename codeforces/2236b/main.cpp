#include <iostream> // for cin, cout
#include <string>
#include <vector> // for vector

using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> arr(k);
	for (int i = 0; i < n; i++)
		arr[i % k] += (s[i] == '1');
	for (int i = 0; i < k; i++) {
		if (arr[i] % 2 == 1) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}
