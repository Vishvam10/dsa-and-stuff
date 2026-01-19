package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstFromPreorder(arr []int) *TreeNode {
	ind := 0

	var solve func(bound int) *TreeNode
	solve = func(bound int) *TreeNode {

		if ind >= len(arr) {
			return nil
		}

		if arr[ind] > bound {
			return nil
		}

		// fmt.Println("node, bound : ", arr[ind], bound)
		root := &TreeNode{arr[ind], nil, nil}
		ind++

		root.Left = solve(root.Val)
		root.Right = solve(bound)

		return root
	}

	return solve(1 << 31)

}
