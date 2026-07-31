class Solution {
public:
    int t_Sum = 0;
    int solve(vector<int>& nums) {
        t_Sum = nums[0];
        int currSum = nums[0];
        int minSum = nums[0];
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            currSum = min(nums[i], nums[i] + currSum);
            minSum = min(minSum, currSum);
            t_Sum += nums[i];
        }
        return minSum;
    }
    int solve1(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = solve(nums);
        int maxSum = solve1(nums);
        int circular_Sum=t_Sum-minSum;
        if(maxSum>0)return max(circular_Sum,maxSum);
        return maxSum;
    }
};