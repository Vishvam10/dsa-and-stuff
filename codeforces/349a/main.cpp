#include <iostream> // for cin, cout
#include <vector>   // for vector

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int a = 0, b = 0;
	for (const auto& x : arr) {
		if (x == 25) {
			a++;
		} else if (x == 50) {
			if (a < 1) {
				cout << "NO" << "\n";
				return;
			}
			a--;
			b++;
		} else if (x == 100) {
			if (b >= 1 && a >= 1) {
				b--;
				a--;
			} else if (a >= 3) {
				a -= 3;
			} else {
				cout << "NO" << "\n";
				return;
			}
		}
	}
	cout << "YES" << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
