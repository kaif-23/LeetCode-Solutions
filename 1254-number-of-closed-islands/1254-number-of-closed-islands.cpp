class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 1;
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (auto dir : directions) {
                int in = i + dir[0];
                int jn = j + dir[1];
                if (in >= 0 && in < m && jn >= 0 && jn < n &&
                    grid[in][jn] == 0) {
                    grid[in][jn] = 1;
                    que.push({in, jn});
                }
            }
        }
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;
        // First and last rows
        for (int j = 0; j < n; j++) {

            if (grid[0][j] == 0) {
                cnt = bfs(grid, 0, j);
            }

            if (grid[m - 1][j] == 0) {
                cnt = bfs(grid, m - 1, j);
            }
        }
        // First and last columns
        for (int i = 0; i < m; i++) {

            if (grid[i][0] == 0) {
                cnt = bfs(grid, i, 0);
            }

            if (grid[i][n - 1] == 0) {
                cnt = bfs(grid, i, n - 1);
            }
        }
        cnt = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    cnt += bfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};