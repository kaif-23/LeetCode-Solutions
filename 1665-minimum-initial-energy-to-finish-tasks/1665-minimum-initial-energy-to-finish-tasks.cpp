class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int currE = 0;
        int total = 0;

        for (auto vec : tasks) {
            int e = vec[0];
            int req = vec[1];

            if (currE < req) {
                int need = req - currE;
                total += need;
                currE += need;
            }

            currE -= e;
        }

        return total;
    }
};