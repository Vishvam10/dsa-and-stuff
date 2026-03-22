func lengthOfLIS(arr []int) int {
    n := len(arr)
    if n == 0 {
        return 0
    }

    temp := make([]int, n)
    for i := range temp {
        temp[i] = 1
    }

    ans := 1

    for i := 0; i < n; i++ {
        maxLen := 0
        for j := 0; j < i; j++ {
            if arr[i] > arr[j] {
                maxLen = max(maxLen, temp[j])
            }
        }
        temp[i] = 1 + maxLen
        ans = max(ans, temp[i])
    }

    return ans
}