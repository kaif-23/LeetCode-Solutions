class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxprefix(n);
        vector<int> minprefix(n);

        // Prefix maximum
        maxprefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxprefix[i] = max(maxprefix[i - 1], nums[i]);
        }

        // Suffix minimum
        minprefix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minprefix[i] = min(minprefix[i + 1], nums[i]);
        }

        // Find first stable index
        for (int i = 0; i < n; i++) {
            if (maxprefix[i] - minprefix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};