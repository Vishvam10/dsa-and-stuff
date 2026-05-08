class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i = 3; i * i <= n; i += 2) {
            if(n % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            for(int d = 1; d * d <= x; d++) {
                if(x % d == 0) {
                    if(isPrime(d)) mp[d].push_back(i);
                    int other = x / d;
                    if(other != d && isPrime(other)) mp[other].push_back(i);
                }
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> used;

        while(!q.empty()) {
            auto [i, steps] = q.front();
            q.pop();

            if(i == n - 1) return steps;

            if(i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = 1;
                q.push({i - 1, steps + 1});
            }

            if(i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = 1;
                q.push({i + 1, steps + 1});
            }

            int val = nums[i];
            if(isPrime(val) && !used.count(val)) {

                used.insert(val);

                for(int nxt : mp[val]) {
                    if(!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push({nxt, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};