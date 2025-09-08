/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func abs(a int) int{
    if(a<0){
        return -a
    }
    return a
}
func checkHeight(root *TreeNode) int{
    if root==nil{
        return 0
    }
    if root.Left==nil && root.Right==nil{
        return 1
    }
    leftHeight:= checkHeight(root.Left)
    if leftHeight==-1{
        return -1
    }
    rightHeight:= checkHeight(root.Right)
    if rightHeight==-1{
        return -1
    }
    if abs(leftHeight-rightHeight)>1{
        return -1
    }
    return max(leftHeight,rightHeight)+1
}
func isBalanced(root *TreeNode) bool {
    return checkHeight(root)!=-1
}