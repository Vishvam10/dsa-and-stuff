#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <cmath>     // for sqrt, round
#include <iostream>  // for cin, cout
#include <limits>    // for numeric_limits if needed
#include <map>       // for map
#include <numeric>   // for reduce, iota
#include <queue>     // for queue
#include <set>       // for set
#include <sstream>   // for getline
#include <string>    // for string operations
#include <vector>    // for vector

using namespace std;

#define READ(v) for(auto &x : (v)) cin >> x
#define PRINT(v) for(const auto& x : v) cout << x << " ";

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<bool> ans(n, false);
    READ(arr);

    int left = 0;
    for(int i = n - 1; i >= 0; --i) {
        left = max(left, arr[i]);
        if(left > 0) {
            left--;
            ans[i] = true;
        }
    }
    PRINT(ans);
    cout << "\n";
    return;
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
