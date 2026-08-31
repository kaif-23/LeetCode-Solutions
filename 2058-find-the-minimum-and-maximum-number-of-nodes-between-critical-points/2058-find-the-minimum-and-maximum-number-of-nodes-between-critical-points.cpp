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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next->next == nullptr)
            return {-1, -1};

        int idx = 1;

        ListNode* prev = head;
        ListNode* temp = head->next;
        ListNode* nxt = temp->next;

        vector<int> idxset;

        while (nxt != nullptr) {

            if ((temp->val > prev->val && temp->val > nxt->val) ||
                (temp->val < prev->val && temp->val < nxt->val)) {
                idxset.push_back(idx);
            }

            idx++;

            prev = temp;
            temp = nxt;
            nxt = nxt->next;
        }
        if (idxset.size() < 2)
            return {-1, -1};

        int maxD = idxset.back() - idxset.front();
        int minD = INT_MAX;

        for (int i = 1; i < idxset.size(); i++) {
            minD = min(minD, idxset[i] - idxset[i - 1]);
        }

        return {minD, maxD};
    }
};