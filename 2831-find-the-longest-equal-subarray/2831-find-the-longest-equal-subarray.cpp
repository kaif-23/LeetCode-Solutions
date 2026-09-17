class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxFreq=0;
        int left=0;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            maxFreq=max(maxFreq,mp[nums[r]]);
            
            if((r-left+1)-maxFreq>k){
                mp[nums[left]]--;
                left++;
            }
        }
        return maxFreq;
    }
};