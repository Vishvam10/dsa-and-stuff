#include <iostream>  // for cin, cout

using namespace std;

using ull = unsigned long long int;


// bool pal(ull x) {
//     ull orig = x, rev = 0;
//     while (x > 0) {
//         rev = rev * 10 + x % 10;
//         x /= 10;
//     }
//     return orig == rev;
// }

// void solve() {
//     ull n;
//     cin >> n;
//     for (ull a = 0; a <= n; a++) {
//         ull b = n - a;
//         if (pal(a) && b % 12 == 0) {
//             cout << a << " " << b << "\n";
//             return;
//         }
//     }
//     cout << "-1" << "\n";
//     return;
// }


// Instead of brute force, just fix a to be a one digit palindrome instead.
// a must be equal to (n % 12) ... for remainder 10 and 11, we can just use
// these 2 digit palindromes : 22 (22 & 12 = 10) and 11 (11 % 12 == 11)

void solve() {
    ull n;
    cin >> n;

    ull r = n % 12;
    ull a;

    if (r <= 9) a = r;
    else if (r == 10) a = 22;
    else a = 11;

    if (a > n) cout << -1 << '\n';
    else cout << a << " " << n - a << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
