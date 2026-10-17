class Solution {
public:
int getdigitSum(int num){
    int sum=0;
    while(num){
        int digit=num%10;
        sum+=digit;
        num/=10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        vector<int>afterSort(nums);
        sort(begin(afterSort),end(afterSort),[&](int num1,int num2){
            int sum1=getdigitSum(num1);
            int sum2=getdigitSum(num2);
            if(sum1!=sum2){
                return sum1<sum2;
            }
            return num1<num2;
        });
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]=i;
        }

        int swapCnt=0;
        for(int i=0;i<nums.size();i++){
            int rightValue=afterSort[i];
            int currValue=nums[i];
            if(rightValue==currValue)continue;
            int idx=mp[rightValue];
            swap(nums[idx],nums[i]);
            mp[rightValue]=i;
            mp[currValue]=idx;
            swapCnt++;
        }
        return swapCnt;
    }
};