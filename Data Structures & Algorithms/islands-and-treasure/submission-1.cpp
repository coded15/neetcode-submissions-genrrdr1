class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Add all treasure cells
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {

            auto current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            for (int i = 0; i < 4; i++) {

                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 2147483647) {

                    grid[nr][nc] = grid[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }
    }
};