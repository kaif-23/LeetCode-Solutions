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

        if (px == py)
            return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& edge : edges) {

            Union(edge[0], edge[1]);
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int parent = find(i);
            mp[parent]++;
        }
        long long remaining = n;
        long long ans = 0;
        for (auto& it : mp) {
            int size = it.second;
            ans += size * (remaining - size);
            remaining -= size;
        }
        return ans;
    }
};