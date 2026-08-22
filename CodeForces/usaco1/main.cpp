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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    int ans = 0.0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int k = j + 1; k < n; ++k) {
                auto [x1, y1] = arr[i];
                auto [x2, y2] = arr[j];
                auto [x3, y3] = arr[k];

                bool valid =
                    (y1 == y2 && (x1 == x3 || x2 == x3)) ||
                    (y1 == y3 && (x1 == x2 || x2 == x3)) ||
                    (y2 == y3 && (x1 == x2 || x1 == x3));

                if (!valid) continue;

                int area = abs((
                    (x1 * (y2 - y3)) +
                    (x2 * (y3 - y1)) +
                    (x3 * (y1 - y2))
                ));
                ans = max(ans, area);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    solve();
}
