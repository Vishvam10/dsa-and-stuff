class Solution {
public:
  typedef vector<int> vec;
  typedef vector<vector<int>> vec2d;

  int search(vec2d &arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (arr[mid][0] < target)
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }

  vec2d insert(vec2d &arr, vec &newInterval) {
    if (arr.empty())
      return {newInterval};

    int ind = search(arr, newInterval[0]);
    arr.insert(arr.begin() + ind, newInterval);

    // Now, just merge intervals
    vec2d ans;

    ans.emplace_back(arr[0]);

    for (int i = 1; i < arr.size(); ++i) {
      vec &prev = ans.back();
      vec &cur = arr[i];

      if (cur[0] <= prev[1]) {
        prev[0] = min(prev[0], cur[0]);
        prev[1] = max(prev[1], cur[1]);
      } else {
        ans.emplace_back(cur);
      }
    }
    return ans;
  }
};