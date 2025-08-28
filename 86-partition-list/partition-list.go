/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    before:=new(ListNode)
    before.Val=-1
    after:=new(ListNode)
    after.Val=-1
    beforeCurr:=before
    afterCurr:=after
    for head!=nil{
        if head.Val<x{
            beforeCurr.Next=head
            beforeCurr=head
        }else{
            afterCurr.Next=head
            afterCurr=head
        }
        head=head.Next
    }
    beforeCurr.Next=after.Next
    afterCurr.Next=nil
    return before.Next
}