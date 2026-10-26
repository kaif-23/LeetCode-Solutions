class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };

    int bfs(vector<vector<int>>& grid, int i, int j,
            vector<vector<bool>>& visited) {

        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = true;

        int perimeter = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Outside boundary
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n) {

                    perimeter++;
                }

                // Water
                else if (grid[nx][ny] == 0) {
                    perimeter++;
                }

                // Land
                else if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans += bfs(grid, i, j, visited);
                }
            }
        }

        return ans;
    }
};