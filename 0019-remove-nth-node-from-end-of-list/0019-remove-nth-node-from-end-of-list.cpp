/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //    ListListNode* dummyHead=new ListListNode();
    //    dummyHead->next=head;
       ListNode* fastp = head;
    
    ListNode* slowp = head;

    // Move the fastp pointer N ListNodes ahead
    for (int i = 0; i < n; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth ListNode from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth ListNode from the end
    ListNode* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
    
};