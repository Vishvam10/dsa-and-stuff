class Solution {
public:
  bool isNStraightHand(vector<int> &arr, int sz) {
    int n = arr.size();
    if (n % sz != 0)
      return false;

    // We need the keys to be in sorted order .. so no unordered_map
    map<int, int> mp;

    // If arr[i] is included at beginning, then arr[i] + 1, arr[i] + 2,
    // arr[i] + 3, ..., arr[i] + (k - 1) MUST also be there

    for (const auto &x : arr) {
      mp[x]++;
    }

    auto it = mp.begin();

    while (it != mp.end()) {

      int ele = it->first;
      int freq = it->second;

      if (freq == 0) {
        ++it;
        continue;
      }

      for (int i = 0; i < sz; ++i) {
        if (mp[ele + i] < freq)
          return false;
        mp[ele + i] -= freq;
      }

      ++it;
    }

    return true;
  }
};