class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>>result;
        vector<vector<int>>mp(n+1);
        for(int i=0; i<n;i++){
            int L=groupSizes[i];
            mp[L].push_back(i);
            if(mp[L].size()==L){
                result.push_back(mp[L]);
                mp[L]={};
            }
        }
        return result;
        
    }
};