class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(auto it:nums1){
            int l=0;
            int r=nums2.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums2[mid]==it){
                    return it;
                }else if(nums2[mid]>it){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};