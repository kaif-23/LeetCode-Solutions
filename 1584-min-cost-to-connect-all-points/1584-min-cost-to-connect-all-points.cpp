class Solution {
public:
typedef pair<int,int> P;
int primsAlgo(vector<vector<pair<int,int>>>&adj){
    int n=adj.size();
    int sum=0;
    priority_queue<P,vector<P>,greater<P>>pq;
    vector<int>inMST(n,false);
    pq.push({0,0});
    while(!pq.empty()){
        auto [wt,u]=pq.top();
        pq.pop();
        if(inMST[u]) continue;
        sum+=wt;
        inMST[u]=true;
        for(auto& edge:adj[u]){
            auto [v,wt]=edge;
             if (!inMST[v])
                pq.push({wt,v});
        }
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[j][0]-points[i][0])+ abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
       return primsAlgo(adj);        
    }
};