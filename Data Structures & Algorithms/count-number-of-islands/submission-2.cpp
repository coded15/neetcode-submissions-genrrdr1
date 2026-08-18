class Solution {
private:
    void markNeighboursAsVisited(vector<vector<char>>& grid, int i, int j) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        markNeighboursAsVisited(grid, i + 1, j);
        markNeighboursAsVisited(grid, i - 1, j);
        markNeighboursAsVisited(grid, i, j + 1);
        markNeighboursAsVisited(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    markNeighboursAsVisited(grid, i, j);
                }
            }
        }
        return islands;
    }
};