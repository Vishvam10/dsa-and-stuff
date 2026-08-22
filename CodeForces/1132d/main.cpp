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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), goneIn(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    // Need to go from the first goneIn or else it'll be gone
    ll low = 0, high = 2e18, ans = -1;

    auto f = [&](ll power) {
        vector<vector<int>> minutes(k + 1);
        vector<int> charges(n, 0);

        for(int i = 0; i < n; ++i) {
            ll goneIn = (a[i] / b[i]) + 1;
            // If goneIn >= k, we can simply ignore them as
            // they don't require charging
            if(goneIn <= k - 1) {
                minutes[goneIn].emplace_back(i);
            }
        }

        int ind = 0;

        // < k as we don't care about the charges at time >= k
        for(int min = 0; min < k; min++) {

            // Pick the laptop that needs charging
            while(ind < k && minutes[ind].empty()) ind++;

            // No one needs charging
            if(ind >= k) return true;

            // Already gone
            if(ind <= min) return false;

            int i = minutes[ind].back();
            minutes[ind].pop_back();

            charges[i]++;

            // Charge at time t =
            //      a[i] + charges[i] * power - b[i] * t
            // We want to find time such that this becomes < 0
            // So, t = (a[i] + 1LL * cnt[i] * x) / b[i] + 1
            ll goneIn = (
                (a[i] + 1LL * charges[i] * power) / b[i] + 1
            );

            // Again, if goneIn >= k, then it survives the test
            if(goneIn < k) {
                minutes[goneIn].emplace_back(i);
            }
        }
        return true;
    };

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(f(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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
