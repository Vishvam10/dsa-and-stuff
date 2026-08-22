#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007LL
#define PI 3.1415926535897932384626433832795

using ll = long long;
using ull = unsigned long long;
using ld = long double;

/* ---------- FAST IO ---------- */

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/* ---------- DEBUG ---------- */

template <typename T>
void print_one(const string& name, const T& value) {
    cerr << name << " = " << value << " ";
}

template <typename T, typename... Args>
void debug_print(const string& names, const T& value, const Args&... args) {
    auto comma = names.find(',');
    string name = names.substr(0, comma);

    size_t start = name.find_first_not_of(' ');
    if (start != string::npos)
        name = name.substr(start);

    print_one(name, value);

    if constexpr (sizeof...(args) > 0) {
        debug_print(names.substr(comma + 1), args...);
    } else {
        cerr << '\n';
    }
}

#define debug(...) debug_print(#__VA_ARGS__, __VA_ARGS__)

/* ---------- PRINT HELPERS ---------- */

template <typename T>
void print_v(const vector<T>& v) {
    for (const auto& x : v)
        cout << x << ' ';
    cout << '\n';
}

template <typename T>
void print_v2d(const vector<vector<T>>& v) {
    for (const auto& row : v) {
        for (const auto& x : row)
            cout << x << ' ';
        cout << '\n';
    }
}

/* ---------- MATH ---------- */

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

bool prime(ll n) {
    if (n <= 1)
        return false;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

string to_upper(string s) {
    for (char& c : s)
        if ('a' <= c && c <= 'z')
            c = c - 'a' + 'A';
    return s;
}

string to_lower(string s) {
    for (char& c : s)
        if ('A' <= c && c <= 'Z')
            c = c - 'A' + 'a';
    return s;
}

/* ---------- SOLUTION ---------- */

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll cost =
        (n / 3) * min(3 * a, b) +
        min((n % 3) * a, b);

    cout << cost << '\n';
}

/* ---------- MAIN ---------- */

int main() {
    FastIO();

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
