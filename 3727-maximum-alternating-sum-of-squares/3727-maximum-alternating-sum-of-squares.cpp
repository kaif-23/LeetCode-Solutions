class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int a ,int b){
            return abs(a)<abs(b);
        });
        int left=0;
        int right=n-1;
        int i=0;
        long long ans=0;
        while(left<=right){
            if(i%2!=0){
               ans-=nums[left]*nums[left];
               left++;
               i++;
            }else{
                ans+=nums[right]*nums[right];
                right--;
                i++;
            }
        }
        return ans;

    }
};