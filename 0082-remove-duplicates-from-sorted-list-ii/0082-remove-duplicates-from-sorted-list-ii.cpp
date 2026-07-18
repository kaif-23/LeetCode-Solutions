class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                while(curr->next && curr->val == curr->next->val){
                    curr=curr->next;
                }
                prev->next=curr->next;
            }else{
                prev=prev->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};