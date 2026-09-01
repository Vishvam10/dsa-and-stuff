#include <iostream> // for cin, cout

using namespace std;

void solve() {
	long long int n;
	cin >> n;
	// (−1 + 2) + (−3 + 4) + ... + (−(2k − 1) + 2k)
	cout << ((n % 2 == 0) ? n / 2 : -(n + 1) / 2) << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
