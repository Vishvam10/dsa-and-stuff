package main

func canJump(arr []int) bool {

	n := len(arr)
	ans := n - 1

	for i := n - 2; i >= 0; i-- {
		if i+arr[i] >= ans {
			ans = i
		}
	}

	return ans == 0

}
