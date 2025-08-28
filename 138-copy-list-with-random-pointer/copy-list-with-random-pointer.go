/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    p:=head
    m:=make(map[*Node]*Node)
    dummyNode:=new(Node)
    dummyNode.Val=-1
    temp:=dummyNode
    for p!=nil{
        temp.Next=new(Node)
        temp=temp.Next
        temp.Val=p.Val
        m[p]=temp
        p=p.Next
    }
    p=head
    temp=dummyNode.Next
    for p!=nil{
        if(p.Random==nil){
            temp.Random=nil
            p=p.Next
            temp=temp.Next
        }else{
            temp.Random=m[p.Random]
            p=p.Next
            temp=temp.Next
        }
    }
    return dummyNode.Next
}