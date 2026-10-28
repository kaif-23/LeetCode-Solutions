class Solution {
public:
bool isPossible(vector<int>& nums, int k, int mid) {
        int subarrays = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                subarrays++;
                sum = x;
            }
        }

        return subarrays <= k;
    }
    int shipWithinDays(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n) return -1;

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isPossible(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
