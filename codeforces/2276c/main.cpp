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
using ull = unsigned long long int;

// 2sum on prefix sum remainders ... this reduces it to O(N)
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ull> pre(n), mp(k, 0);
    for(int i = 0; i < n; ++i) {
        ull x;
        cin >> x;
        pre[i] = (i ? pre[i - 1] : 0) + x;
        pre[i] %= k;
    }

    ull ans = 0;

    for(int i = k; i < n; ++i) {
        // Add the newly eligible prefix remainder.
        if(i == k) mp[0]++;
        else mp[pre[i - k - 1]]++;
        ans += mp[pre[i]];
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
