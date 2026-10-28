class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid) {
        int subarray = 1;
        int sum = 0;
        for (int n : nums) {
            if (sum + n <= mid) {
                sum += n;
            } else {
                subarray++;
                sum = n;
            }
        }
        return subarray <= k ? true : false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, k, mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};