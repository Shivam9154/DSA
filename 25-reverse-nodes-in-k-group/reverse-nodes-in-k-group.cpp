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
    ListNode* reverseLL(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL,*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next; 
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode *p=dummyNode;
        ListNode *tail=p->next;
        ListNode *temp;
        ListNode *tailPrev;
        bool isFirstGroup=true;
        while(p->next!=NULL){
            int i;
            for(i=1;i<=k&&p->next;i++){
                p=p->next;
            }
            if(i!=k+1){
                break;
            }
            if(isFirstGroup){
                ListNode *q=p->next;
                p->next=NULL;
                temp=reverseLL(tail);
                head=temp;
                p=tail;
                tail->next=q;
                tail=tail->next;
                tailPrev=p;
                isFirstGroup=false;
            }else{
                ListNode *q=p->next;
                p->next=NULL;
                temp=reverseLL(tail);
                p=tail;
                tail->next=q;
                tail=tail->next;
                tailPrev->next=temp;
                tailPrev=p;
            }
        }
        delete dummyNode;
        return head;
    }
};