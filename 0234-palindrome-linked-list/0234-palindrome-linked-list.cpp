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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
          if (!head || !head->next) return true;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
         ListNode* newhead = reverse(slow);
        ListNode*first=head;
        ListNode*second=newhead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newhead);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverse(newhead);
        return true;

        
    }
};  