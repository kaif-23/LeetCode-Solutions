class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minElment=*min_element(nums1.begin(),nums1.end());
        if(minElment%2==1)return true;
        for(auto& num:nums1){
            if(num%2==1)return false;
        }
        return true;
    }
};