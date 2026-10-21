class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin(), s.end())) return 0;
        if(n == 2) return -1;
        auto [mn, mx] = minmax_element(s.begin() + 1, s.end() - 1);
        if (s[0] <= min(*mn, s[n - 1]) || max(s[0], *mx) <= s[n - 1]) return 1;
        return s[n - 1] < *mn && *mx < s[0] ? 3 : 2;
    }
};
