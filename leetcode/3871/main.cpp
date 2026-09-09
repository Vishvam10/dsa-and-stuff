class Solution {
public:
    long long countCommas(long long n) {

        // 1 to 999  - > 0
        // 1,000 to 999,999  - > 999,000
        // 1,000,000 to 999,999,999  - > 999,000,000
        // 1,000,000,000 to 999,999,999,999  - > 999,000,000,000

        long long ans = 0;
        if (n >= 1000LL) ans += n - 999LL;
        if (n >= 1000000LL) ans += n - 999999LL;
        if (n >= 1000000000LL) ans += n - 999999999LL;
        if (n >= 1000000000000LL) ans += n - 999999999999LL;
        if (n >= 1000000000000000LL) ans += n - 999999999999999LL;
        return ans;

    }
};
