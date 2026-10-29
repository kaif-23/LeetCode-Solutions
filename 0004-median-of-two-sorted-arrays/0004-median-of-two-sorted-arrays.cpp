class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.begin(), nums1.end());
        res.insert(res.end(), nums2.begin(), nums2.end());
        sort(res.begin(),res.end());
        int n=res.size();
        if(n%2==0){
            return double(res[n/2]+res[(n/2)-1])/2;
        }
        return res[n/2];

    }
};
