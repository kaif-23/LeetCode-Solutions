class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxelement=0;
        int secmax=0;
        for(auto& num:nums){
            if(num>=maxelement){
                secmax=maxelement;
                maxelement=num;
            }else if(num>secmax) secmax=num;
        }
        return (maxelement-1)*(secmax-1);
    }
};