#include <algorithm>        // for max, min, sort, etc.
#include <climits>          // for LLONG_MAX
#include <cmath>            // for sqrt, round
#include <iostream>         // for cin, cout
#include <limits>           // for numeric_limits if needed
#include <map>              // for map
#include <numeric>          // for reduce
#include <queue>            // for queue
#include <set>              // for set
#include <sstream>          // for getline
#include <string>           // for string operations
#include <vector>           // for vector
#include <unordered_map>    // for unordered_map

using namespace std;

void solve() {
    int n, v;
    cin >> n;
    // from -> to
    unordered_map<int, int> mp;
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> v;
        mp[i] = v;
    }
    for(int i = 1; i <= n; ++i) {
        vector<bool> vis(n + 1, false);
        int cur = i;
        while(!vis[cur]) {
            vis[cur] = true;
            cur = mp[cur];
        }
        ans[i] = cur;
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
