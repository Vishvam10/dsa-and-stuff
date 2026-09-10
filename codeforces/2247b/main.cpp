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
    int n, k, m;
    cin >> n >> k >> m;
    if(k > m) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";

    // We can't do : m m m and rest all 1s because the min subarray
    // size that has sum divisble by m = 1 which can be < k
    // So, we do it in cycles of k length in this fashion :
    // (m - k + 1) followed by (k - 1) 1s
    // So, sum after each cycle = m - k + 1 + (k - 1) = m
    for (int i = 0; i < n; i++) {
        if (i % k == 0) cout << m - k + 1 << " ";
        else cout << 1 << " ";
    }

    cout << "\n";
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
