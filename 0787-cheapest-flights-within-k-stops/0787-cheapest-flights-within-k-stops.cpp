class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst)
                return cost;

            if (stops == k + 1)
                continue;

            if (cost > dist[u][stops])
                continue;

            for (auto& [v, wt] : adj[u]) {
                int newCost = cost + wt;
                int newStops = stops + 1;

                if (newCost < dist[v][newStops]) {
                    dist[v][newStops] = newCost;
                    pq.push({newCost, v, newStops});
                }
            }
        }

        return -1;
    }
};