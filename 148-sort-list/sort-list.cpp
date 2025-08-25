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
    ListNode *findMid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *leftHead,ListNode *rightHead){
        ListNode *dummyNode=new ListNode(-1);
        ListNode *list1=leftHead, *list2=rightHead;
        ListNode *temp=dummyNode;
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1){
            temp->next=list1;
        }else{
            temp->next=list2;
        }
        ListNode *head=dummyNode->next;
        delete dummyNode;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *mid= findMid(head);
        ListNode *leftHead=head;
        ListNode *rightHead=mid->next;
        mid->next=NULL;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return merge(leftHead,rightHead);      
    }
};