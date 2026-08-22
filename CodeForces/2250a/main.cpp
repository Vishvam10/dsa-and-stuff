#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <cmath>     // for sqrt, round
#include <iostream>  // for cin, cout
#include <limits>    // for numeric_limits if needed
#include <map>       // for map
#include <numeric>   // for reduce
#include <queue>     // for queue
#include <set>       // for set
#include <sstream>   // for getline
#include <string>    // for string operations
#include <vector>    // for vector

using namespace std;
using ll = long long int;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    if(n == 1) {
        cout << "NO" << "\n";
        return;
    }

    // Initially, k ∈ [-INF, INF]
    pair<ll, ll> k = {LLONG_MIN, LLONG_MAX};

    // i moves to (i + 1) OR (i - 1)
    // If i moves to (i + 1), then (i + 1) must move to (i - 1)
    // If i moves to (i - 1), then (i - 1) must move to i
    // So, pair wise something ?
    //
    // 3 1 9 2 8 3
    // r l r l r l ...
    //
    // 1e9 1 9 2 8 3
    // r   l r l r l
    // [-INF, 1e9] => [1, 1e9] => [1, 9] => [2, 9] => [2, 8] => [3, 8]

    // 2 1
    // r l
    // [-INF, 2] => [1, 2]

    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            // arr[i] must be > k => k must be [-INF, arr[i]]
            k.second = min(k.second, static_cast<ll>(arr[i]));
        } else{
            // arr[i] must be < k => k must be [arr[i], INF]
            k.first = max(k.first, static_cast<ll>(arr[i]));
        }
    }
    if (n % 2 == 0 && k.first + 2 <= k.second) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
