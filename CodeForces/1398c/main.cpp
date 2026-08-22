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
#include <unordered_map>
#include <vector>    // for vector

using namespace std;

using ll = long long int;

// pre[r] - pre[l - 1] = (r - ; + 1)
// => pre[r] - r = pre[l - 1] - (l - 1)
// We can use 2sum here on val[k] where val[k] = pre[k] - k
void solve() {
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;

    unordered_map<int, ll> mp;
    mp[0] = 1;

    int pre = 0;

    for (int i = 1; i <= n; i++) {
        pre += s[i - 1] - '0';
        int key = pre - i;
        ans += mp[key];
        mp[key]++;
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
