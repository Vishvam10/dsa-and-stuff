#include <algorithm>
#include <cstddef>
#include <iostream>  // for cin, cout

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    // 8 3 9 4 10 5 11
    // 3 4 5 8 9 10 11
    // 8 (3 + k1) 9 (4 + k2) 10 (9 + k3) 10
    // k1 ∈ {5, 6}, k2 ∈ {5, 6}, k3 ∈ {1, 1}, ...
    // So, k must be max of these differences ? And then if arr is
    // sorted after we add that min k ...

    int k = 0;

    for(int i = 1; i < n - 1; ++i) k = max(k, arr[i - 1] - arr[i]);
    for(int i = 1; i < n; ++i) arr[i] += (arr[i] < arr[i - 1]) ? k : 0;

    if(is_sorted(arr.begin(), arr.end())) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
