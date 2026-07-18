
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* curr = head;
        ListNode* smallP = small;
        ListNode* largeP = large;

        while (curr) {
            if (curr->val < x) {
                smallP->next = curr;
                smallP = smallP->next;
            } else {
                largeP->next = curr;
                largeP = largeP->next;
            }
            curr = curr->next;
        }
        smallP->next = large->next;
        largeP->next = nullptr;
        return small->next;
    }
};