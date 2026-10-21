class Solution {
public:
    int dijkstra(int s, int target, vector<vector<pair<int, int>>>& adj) {
        int v = adj.size();

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> res(v, INT_MAX);

        res[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > res[node]) continue;

            if (node == target)
                return d;

            for (auto& [adjNode, cost] : adj[node]) {
                if (d + cost < res[adjNode]) {
                    res[adjNode] = d + cost;
                    pq.push({res[adjNode], adjNode});
                }
            }
        }

        return -1;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int, int>>> adj(m * n);

        int directions[4][2] = {
            {-1, 0}, {1, 0}, {0, 1}, {0, -1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = i * n + j;

                for (int k = 0; k < 4; k++) {
                    int nr = i + directions[k][0];
                    int nc = j + directions[k][1];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    int v = nr * n + nc;
                    int cost = grid[nr][nc];

                    adj[u].push_back({v, cost});
                }
            }
        }

        int target = m * n - 1;
        return dijkstra(0, target, adj);
    }
};