/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}
func diameterOfBinaryTree(root *TreeNode) int {
	ans := 0
    var height func(node *TreeNode) int
	height = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		leftHeight := height(node.Left)
		rightHeight := height(node.Right)
		ans = max(ans, leftHeight+rightHeight)
		return max(leftHeight, rightHeight) + 1
	}
    height(root)
	return ans
}