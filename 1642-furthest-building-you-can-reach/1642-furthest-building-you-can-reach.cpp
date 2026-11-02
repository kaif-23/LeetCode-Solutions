class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int> pq;

        int n = heights.size();

        for (int i = 0; i < n - 1; i++) {

            int diff = heights[i + 1] - heights[i];

            if (diff <= 0)
                continue;

            // Initially use bricks.
            bricks -= diff;
            pq.push(diff);

            // If bricks become negative, replace
            // the largest brick expense with a ladder.
            if (bricks < 0) {

                if (ladders > 0) {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                else {
                    return i;
                }
            }
        }

        return n - 1;
    }
};