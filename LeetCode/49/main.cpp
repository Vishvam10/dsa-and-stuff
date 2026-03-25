class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < arr.size(); ++i) {
            string s = arr[i];
            sort(s.begin(), s.end());

            mp[s].push_back(arr[i]);
        }

        vector<vector<string>> ans;
        for (auto& [key, val] : mp) {
            ans.push_back(val);
        }
        return ans;
    }
};