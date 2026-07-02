class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        for(int i=0; i<n;){
            int start=nums[i];
            int j=i;
            while(j+1<n && nums[j+1]==nums[j]+1){
                j++;
            }
            if(nums[j]==start){
                res.push_back(to_string(start));
            }else{
                res.push_back(to_string(start)+"->"+to_string(nums[j]));
            }
            i=j+1;
        }
        return res;
    }
};