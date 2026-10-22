
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto& edge : connections) {
            if (find(edge[0]) != find(edge[1])) {
                Union(edge[0], edge[1]);
                components--;
            }
        }

        return components - 1;
    }
};
