class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int bestSum=INT_MIN;
        for(int num :nums){
            currSum=max(num,currSum+num);
            bestSum=max(bestSum,currSum);
        }
        return bestSum;
    }
};