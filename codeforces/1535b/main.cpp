#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int odd = 0, even = 0;
    for (int& x : arr) {
        cin >> x;
        if (x % 2 == 0) even++;
        else odd++;
    }

    // Optimal ordering is :
    // even, even, even, ..., odd, odd, odd, ...
    long long ans = 1LL * even * (even - 1) / 2;
    ans += 1LL * even * odd;

    // Among odd numbers, gcd(ai, 2 * aj) > 1
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) continue;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] % 2 == 0) continue;
            ans += (gcd(arr[i], arr[j]) > 1);
        }
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


// #include <cassert>
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// int gcd(int a, int b) {
// 	if (a == 0) {
// 		return b;
// 	}
// 	return gcd(b % a, a);
// }
//
// void solve() {
//
// 	int n, ans = 0;
// 	vector<int> arr;
// 	vector<int> temp;
//
// 	cin >> n;
//
// 	for (int i = 0; i < n; i++) {
// 		int x;
// 		cin >> x;
// 		if (x % 2 == 0) {
// 			arr.emplace_back(x);
// 		} else {
// 			temp.emplace_back(x);
// 		}
// 	}
//
// 	for (int i = 0; i < temp.size(); i++) {
// 		arr.emplace_back(temp[i]);
// 	}
//
// 	for (int i = 0; i < n; i++) {
// 		for (int j = i + 1; j < n; j++) {
// 			if (gcd(arr[i], 2 * arr[j]) > 1) {
// 				ans++;
// 			}
// 		}
// 	}
//
// 	cout << ans << "\n";
// }
//
// int main() {
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		solve();
// 	}
// }
