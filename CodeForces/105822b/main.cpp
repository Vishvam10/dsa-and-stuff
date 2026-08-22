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
    vector<ll> arr(n), diff(n - 1);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; ++i) diff[i] = arr[i + 1] - arr[i];
    ll minDiff = diff[0], ans = LLONG_MAX;
    for(int i = 2; i < n - 1; ++i) {
        ans = min(ans, minDiff + diff[i]);
        minDiff = min(minDiff, diff[i - 1]);
    }
    cout << ans << "\n";
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
