class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum(nums.size(), 0);
        vector<int> suffixSum(nums.size(), 0);

        // Prefix Sum INCLUDING current index i
        prefixSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Suffix Sum INCLUDING current index i
        suffixSum[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum[i]==suffixSum[i]) {
                return i;
            }
        }
        return -1;
    }
};