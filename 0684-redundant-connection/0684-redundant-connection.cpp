class Solution {
public:
vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } 
        else if (rank[py] > rank[px]) {
            parent[px] = py;
        } 
        else {
            parent[px] = py;
            rank[py]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
         parent.resize(n+1);
        rank.resize(n+1, 1);

        for (int i = 1; i <=n; i++) {
            parent[i] = i;
        }
        

        for(auto edge:edges){
             int u = edge[0];
            int v = edge[1];
            if(find(u) ==find(v)) {
                return edge;
            }
            Union(u, v);
        }
       
        return {};
    }
};