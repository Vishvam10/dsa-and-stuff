#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

void solve(int t) {
    cout << "CASE : " << t << "\n";
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);

    cout << "\nans : ";
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
}
