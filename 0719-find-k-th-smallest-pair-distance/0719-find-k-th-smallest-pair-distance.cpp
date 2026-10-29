class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int n = nums.size();
        int cnt = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }

            cnt += j - i - 1;
        }

        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];

        while (l < r) {
            int mid = l + (r - l) / 2;

            int cnt = countPairs(nums, mid);

            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};