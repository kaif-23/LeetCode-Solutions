class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>maxfromright(n);
        int mx=0;
        for(int i=n-1; i>=0;i--){
            if(mx<=nums[i]){
                mx=nums[i];
            }
            maxfromright[i]=mx;
        }
        int j=0; int i=0;
        while(j<n){
            if(nums[i]<=maxfromright[j]){
               ans=max(ans,j-i);
               j++;
            }else {
                i++;
            }
        }
        return ans;
    }

};