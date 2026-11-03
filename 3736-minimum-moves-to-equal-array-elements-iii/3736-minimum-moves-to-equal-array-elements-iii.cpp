class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int maxE=*max_element(nums.begin(),nums.end());
        for(auto n:nums){
            ans+=(maxE-n);
        }
        return ans;
    }
};