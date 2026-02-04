class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i = 0; i < n; ++i) {
            mp[arr[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }
        while(!pq.empty() && k > 0) {
            auto [freq, ele] = pq.top();
            pq.pop();
            ans.emplace_back(ele);
            k--;
        }
        return ans;
    }
};