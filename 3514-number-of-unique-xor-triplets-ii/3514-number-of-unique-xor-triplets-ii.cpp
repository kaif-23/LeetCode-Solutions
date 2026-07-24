class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0; i<n;i++){
            for(int j=i;j<n;j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        for(auto& st:s1){
            for(int i=0; i<n;i++){
                s2.insert(nums[i]^st);
            }
        }
        return s2.size();
    }
};