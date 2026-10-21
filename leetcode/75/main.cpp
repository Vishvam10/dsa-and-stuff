class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0, left = 0, right = n - 1;
        while(i <= right) {
            if(arr[i] == 0) swap(arr[i++], arr[left++]);
            else if(arr[i] == 2) swap(arr[i], arr[right--]);
            else i++;
        }
    }
};
