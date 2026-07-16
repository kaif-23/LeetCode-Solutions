class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int currMax = INT_MIN;
        for (auto& num : nums) {
           currMax=max(currMax,num);
            prefixGcd.push_back(__gcd(currMax, num));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};