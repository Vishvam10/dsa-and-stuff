package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {

	if root == nil {
		return nil
	}

	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	} else if root.Val < key {
		root.Right = deleteNode(root.Right, key)
	} else {

		// If left subtree doesn't exist, return right subtree
		if root.Left == nil {
			return root.Right
		}

		// If right subtree doesn't exist, return left subtree
		if root.Right == nil {
			return root.Left
		}

		// If both subtree exists, return inorder successor
		cur := root.Right
		for cur.Left != nil {
			cur = cur.Left
		}
		root.Val = cur.Val

		// We still need to delete the inorder successor (IS) node which
		// might be all the way down ... this will just point the IS's parent
		// to nil as IS is always a leaf node
		root.Right = deleteNode(root.Right, cur.Val)
	}

	return root
}
