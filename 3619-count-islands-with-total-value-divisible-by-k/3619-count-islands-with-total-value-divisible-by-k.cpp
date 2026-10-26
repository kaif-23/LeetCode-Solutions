class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int bfs(vector<vector<int>>& grid, int i, int j, int k) {
        queue<pair<int, int>> que;
        long long sum = grid[i][j];
        que.push({i, j});
        grid[i][j] = 0;
        cout<<"inital sum"<<sum;
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (auto dir : directions) {
                int in = i + dir[0];
                int jn = j + dir[1];
                if (in >= 0 && in < m && jn >= 0 && jn < n &&
                    grid[in][jn] != 0) {
                    sum += grid[in][jn];
                    grid[in][jn] = 0;
                    que.push({in, jn});
                }
            }
        }
        cout<<sum<<endl;
        return (sum % k == 0) ? 1 : 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    cnt += bfs(grid, i, j, k);
                }
            }
        }

        return cnt;
    }
};