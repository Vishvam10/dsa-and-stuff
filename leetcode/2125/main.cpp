class Solution {
public:
    int numberOfBeams(vector<string>& mat) {
        int prev = -1, ans = 0;
        for(const auto& row : mat) {
            int ones = count(row.begin(), row.end(), '1');
            if(prev == -1) {
                prev = ones;
            } else {
                if(ones != 0) {
                    ans += (prev * ones);
                    prev = ones;
                }
            }
        }
        return ans;
    }
};
