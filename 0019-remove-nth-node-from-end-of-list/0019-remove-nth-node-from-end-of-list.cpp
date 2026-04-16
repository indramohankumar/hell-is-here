class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;

        // count length
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // if head needs to be removed
        if (cnt == n) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        int res = cnt - n;
        temp = head;

        // move to node before target
        while (temp != NULL) {
            res--;
            if (res == 0) break;
            temp = temp->next;
        }

        // delete node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};