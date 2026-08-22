#include <climits>
#include <iostream>  // for cin, cout

using namespace std;

using ull = unsigned long long int;


void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    int cnt = 0, ans = INT_MAX;
    // max moves = max(a, b) - min(a, b)
    // min moves = divide till close enough then subtract
    // remainder number of times ?
    while(true) {
        if(a < b) swap(a, b);
        ans = min(ans, abs(a - b) + cnt);
        if(a == b) break;
        a /= x;
        cnt++;
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
