class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minIdx=min_element(nums.begin(),nums.end())-nums.begin();
        int maxIdx=max_element(nums.begin(),nums.end())-nums.begin();

       int rightIdx=max(minIdx,maxIdx);
       int leftIdx=min(minIdx,maxIdx);
       int option1=leftIdx+1+(n-rightIdx);
       int option2=rightIdx+1;
       int option3=n-leftIdx;
       return min({option1,option2,option3});

    }
};