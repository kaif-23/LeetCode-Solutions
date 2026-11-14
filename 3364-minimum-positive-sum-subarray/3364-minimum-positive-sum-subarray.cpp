class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        
        int minSum = INT_MAX;
        for (int window = l; window <= r; window++) {
            int j = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (i - j + 1 > window) {
                    sum -=nums[j];
                    j++;
                }
                if (i - j + 1 == window) {
                    if (sum > 0) {
                        minSum = min(minSum, sum);
                    }
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};