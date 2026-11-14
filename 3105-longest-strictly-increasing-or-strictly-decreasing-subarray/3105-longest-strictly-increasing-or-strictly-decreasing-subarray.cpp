
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        // Increasing sliding window
        int l = 0;
        for (int r = 1; r < n; r++) {
            if (nums[r] <= nums[r - 1]) {
                l = r;
            }

            ans = max(ans, r - l + 1);
        }

        // Decreasing sliding window
        l = 0;
        for (int r = 1; r < n; r++) {
            if (nums[r] >= nums[r - 1]) {
                l = r;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
