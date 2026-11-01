class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int ans = 0;
        int n = costs.size();

        for (int i = 0; i < n; i++) {

            if (i < n / 2) {
                ans += costs[i][0];  // City A
            } else {
                ans += costs[i][1];  // City B
            }
        }

        return ans;
    }
};