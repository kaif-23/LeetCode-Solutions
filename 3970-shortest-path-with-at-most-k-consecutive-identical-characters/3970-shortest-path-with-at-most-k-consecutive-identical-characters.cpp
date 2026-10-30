
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (dist[node][cnt] < d)
                continue;

            if (node == n - 1)
                return d;

            for (auto vec : adj[node]) {

                int adjNode = vec.first;
                int wt = vec.second;

                int newcnt;

                if (labels[adjNode] == labels[node])
                    newcnt = cnt + 1;
                else
                    newcnt = 1;

                if (newcnt > k)
                    continue;

                if (d + wt < dist[adjNode][newcnt]) {

                    dist[adjNode][newcnt] = d + wt;

                    pq.push({d + wt, adjNode, newcnt});
                }
            }
        }

        return -1;
    }
};
