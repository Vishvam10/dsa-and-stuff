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
using ll = long long int;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n), pre(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), pre.begin());
    ll s = accumulate(arr.begin(), arr.end(), 0LL);

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        ll before = pre[r] - (l > 0 ? pre[l - 1] : 0);
        ll after = 1LL * (r - l + 1) * k;
        ll ns = s + (after - before);
        cout << (ns % 2 == 1 ? "YES" : "NO") << '\n';
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
