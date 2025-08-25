/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB){
            return headA;
        }

        ListNode *p=headA,*q=headB;
        int countA=0, countB=0;
        while(p!=NULL && q!=NULL){
            countA++;
            countB++;
            p=p->next;
            q=q->next;
        }
        while(p!=NULL){
            countA++;
            p=p->next;
        }
        while(q!=NULL){
            countB++;
            q=q->next;
        }
        p=headA,q=headB;
        if(countB>countA){
            while(countB!=countA){
                countB--;
                q=q->next;
            }
        }else{
            while(countB!=countA){
                countA--;
                p=p->next;
            }
        }
        while(p->next!=NULL && q->next!=NULL){
            if(p==q){
                return p;
            }
            p=p->next;
            q=q->next;          
        }
        if(p==q){
            return p;
        }
        return NULL;    
    }
};