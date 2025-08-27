/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *curr=head, *prev=NULL, *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *p=head,*tail=head,*temp=head,*tailPrev;
        int count=0;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        k=k%count;
        if(k==0){
            return head;
        }
        p=head;
        for(int i=1;i<count-k;i++){
            p=p->next;
        }
        ListNode *q=p->next;
        p->next=NULL;
        head=reverseLL(head);
        tail->next=q;
        tailPrev=tail;
        tail=tail->next;
        temp=temp->next;
        temp=reverseLL(temp);
        tailPrev->next=temp;
        head=reverseLL(head);
        return head;
    }
};