class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int> pq;

        for(const auto x : arr) {
            pq.push(x);
        }

        while(k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
        
    }
};