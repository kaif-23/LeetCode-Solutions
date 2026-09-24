class Solution {
public:
int sumofdigit(int num){
    int sum=0;
    while(num){
        int lastdigit=num%10;
        sum+=lastdigit;
        num/=10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n;i++){
            int sum=sumofdigit(nums[i]);
            if(sum==i)return i;
        }
        return -1;
    }
};