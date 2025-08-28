/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node *p=head;
       unordered_map<Node*,Node*>m;
       Node *dummyNode=new Node(-1);
       Node *temp=dummyNode;
       while(p){
        temp->next=new Node(p->val);
        temp=temp->next;
        m[p]=temp;
        p=p->next;
       }
       p=head;
       temp=dummyNode->next;
       while(p){
        if(p->random==NULL){
            temp->random=NULL;
            p=p->next;
            temp=temp->next;
        }else{
            temp->random=m[p->random];
            p=p->next;
            temp=temp->next;
        }
       }
       temp=dummyNode->next;
       delete dummyNode;
       return temp;
    }
};