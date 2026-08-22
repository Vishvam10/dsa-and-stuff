#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) {
        int mn = *min_element(arr.begin(), arr.begin() + i);
        ans += min(arr[i], mn);
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
        solve();
    }
}
