class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int sum=0;
        for(int i=1;i<n;i++){
            sum=nums[i]+nums[i-1];
            if(mp.count(sum)){
                return true;
            }else{
                mp[sum]=i;
            }
        }
        return false;
    }
};