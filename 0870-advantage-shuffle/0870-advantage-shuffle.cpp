class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
       unordered_map<int,queue<int>>mp;
       for(int i=0; i<n;i++){
        mp[nums2[i]].push(i);
       }
        vector<int>res(n,-1);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
queue<int>unused;
        while(i<n && j<n){
            if(nums1[i]>nums2[j]){
              int idx=mp[nums2[j]].front();
                mp[nums2[j]].pop();
                j++;
                res[idx]=nums1[i];
            }else{
               unused.push(nums1[i]);
            }
            i++;
        }
        for(int i=0; i<n;i++){
            if(res[i]==-1){
                res[i]=unused.front();
                unused.pop();
            }
        }
        return res;

    }
};