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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int cnt = 0, ans = 0;
    for (int x = 1; x <= m; ++x) {
        int cnt = arr.end() - lower_bound(arr.begin(), arr.end(), x);
        if (2 * x <= m) {
            cnt += (
                upper_bound(arr.begin(), arr.end(), 2 * x) -
                lower_bound(arr.begin(), arr.end(), 2 * x)
            );
        }

        ans = max(ans, cnt);
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
        // cout << "CASE " << t << "\n\n";
        solve();
    }
}
