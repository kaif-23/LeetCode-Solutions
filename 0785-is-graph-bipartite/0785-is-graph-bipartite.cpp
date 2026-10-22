class Solution {
public:
bool bfs(int u,vector<vector<int>>& graph, vector<int> &color,int currColor){
    color[u]=currColor;
    queue<int>que;
    que.push(u);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(auto v:graph[u]){
            if(color[u]==color[v])return false;
            else if(color[v]==-1){
                color[v]=1-color[u];
                que.push(v);
            }
        }
    }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, graph, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};