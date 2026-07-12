class Solution {
public:
void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int &e,int &v){
    vis[u]=true;
    v++;
    e+=adj[u].size();

    for(auto& it: adj[u]){
        if(!vis[it]){
            dfs(it,adj,vis,e,v);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        int res=0;
        for(int i=0; i<n;i++){
            if(vis[i]==true){
                continue;
            }
                int e=0;
                int v=0;
                dfs(i,adj,vis,e,v);
            
            if(e==v*(v-1)){
                res++;
            }
        }
        return res;
    }
};