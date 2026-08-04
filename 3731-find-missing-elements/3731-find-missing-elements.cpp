class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<int>missing;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=mn; i<=mx;i++){
            if (j < nums.size() && nums[j] == i) j++;
            else missing.push_back(i);
        }
        return missing;
    }
};