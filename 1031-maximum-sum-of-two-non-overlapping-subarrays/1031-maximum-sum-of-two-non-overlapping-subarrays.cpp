class Solution {
public:
    int solve(vector<int>&nums,int F,int L){
        int n=nums.size();
        int mend=F+L-1;
        int lSum=0;
        int mSum=0;
        for(int i=0; i<=mend;i++){
            if(i<L)lSum+=nums[i];
            else mSum+=nums[i];
        }
        int maxLSum=lSum;
        int result= maxLSum+mSum;
        for(int i=F+L;i<n;i++){
            lSum+=nums[i-L]-nums[i-L-F];
            mSum+=nums[i]-nums[i-L];
            maxLSum=max(maxLSum,lSum);
            result=max(result,maxLSum+mSum);
        }
        return result;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int F, int L) {
      return  max(solve(nums,F,L),solve(nums,L,F));
    
    }
};