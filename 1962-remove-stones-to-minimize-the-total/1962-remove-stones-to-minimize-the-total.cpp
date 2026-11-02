class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        int ans = 0;

        for (int x : piles) {
            pq.push(x);
            ans += x;
        }

        while (k--) {
            int mx = pq.top();
            pq.pop();

            int removed = mx / 2;
            int updated = mx - removed;

            ans -= removed;
            pq.push(updated);
        }

        return ans;
    }
};