class Solution {
   public:
    queue<pair<int, int>> sequence;
    set<pair<int, int>> visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int maxArea = INT_MIN;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int area = 0;
                // grid contains '1' and '0' chars, not integers
                if ((grid[i][j] == 1) && (visited.find({i, j}) == visited.end())) {
                    area = bfs(i, j, rows, columns, grid, area);
                }
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
    int bfs(int row, int column, int rows, int columns, vector<vector<int>>& grid, int area) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        sequence.push({row, column});
        visited.insert({row, column});

        while (!sequence.empty()) {
            area++;

            auto current = sequence.front();
            sequence.pop();

            int currRow = current.first;
            int currCol = current.second;

            for (int i = 0; i < 4; i++) {
                int r = currRow + directions[i][0];
                int c = currCol + directions[i][1];

                // bounds check FIRST
                if (r >= 0 && r < rows && c >= 0 && c < columns && grid[r][c] == 1 &&
                    visited.find({r, c}) == visited.end()) {
                    sequence.push({r, c});
                    visited.insert({r, c});
                }
            }
        }
        return area;
    }
};
