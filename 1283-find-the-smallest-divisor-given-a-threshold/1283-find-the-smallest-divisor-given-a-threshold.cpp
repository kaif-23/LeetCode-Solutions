class Solution {
public:
   bool solve(vector<int>&nums,int mid,int threshold){
    int sum=0;
    for(int x:nums){
        sum+=((x+mid-1)/mid);
    }
    return sum<=threshold ?true:false;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(nums,mid,threshold)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};