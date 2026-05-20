class Solution {
public:
    int result = 0;
    queue<pair<int, int>> sequence;
    set<pair<int, int>> visited;

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {

                // grid contains '1' and '0' chars, not integers
                if ((grid[i][j] == '1') &&
                    (visited.find({i, j}) == visited.end())) {

                    bfs(i, j, rows, columns, grid);
                    result++;
                }
            }
        }

        return result;
    }

    void bfs(int row, int column,
             int rows,
             int columns,
             vector<vector<char>>& grid) {

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        sequence.push({row, column});
        visited.insert({row, column});

        while (!sequence.empty()) {

            auto current = sequence.front();
            sequence.pop();

            int currRow = current.first;
            int currCol = current.second;

            for (int i = 0; i < 4; i++) {

                int r = currRow + directions[i][0];
                int c = currCol + directions[i][1];

                // bounds check FIRST
                if (r >= 0 && r < rows &&
                    c >= 0 && c < columns &&
                    grid[r][c] == '1' &&
                    visited.find({r, c}) == visited.end()) {

                    sequence.push({r, c});
                    visited.insert({r, c});
                }
            }
        }
    }
};