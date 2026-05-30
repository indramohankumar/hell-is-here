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
ListNode*getkthNode(ListNode*temp,int k){
    k-=1;
    while(temp!=NULL&&k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverseLinkedList(ListNode*head){
    ListNode*prev=NULL;
    ListNode*curr=head;
    while(curr){
        ListNode*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prevlast=NULL;
        while(temp!=NULL){
            ListNode*kthNode=getkthNode(temp,k);
            if(kthNode==NULL){
                if(prevlast) prevlast->next=temp;
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
             reverseLinkedList(temp);
            if(temp==head){
                head=kthNode;
            }
            else {
                prevlast->next=kthNode;

            }
            prevlast=temp;
            temp=nextNode;
        }
        return head;
    }
};