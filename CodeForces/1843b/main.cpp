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
    ll ans = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    ll s = accumulate(arr.begin(), arr.end(), 0, [](ll s, ll x) {
        return s + abs(x);
    });

    bool flag = false;
    for (int x : arr) {
        if (x < 0) {
            if (!flag) {
                ans++;
                flag = true;
            }
        } else if(x > 0) {
            flag = false;
        }
    }
    cout << s << " " << ans << "\n";
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
