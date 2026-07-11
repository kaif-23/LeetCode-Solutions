class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>component(n,-1);
        int compId=0;
        component[0]=compId;
        
        for(int i=1; i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                compId++;
            }
            component[i]=compId;
        }
        vector<bool>res;
        for(auto& q:queries){
            int u=q[0];
            int v=q[1];
            if(component[u]==component[v]){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
return res;
    }
};