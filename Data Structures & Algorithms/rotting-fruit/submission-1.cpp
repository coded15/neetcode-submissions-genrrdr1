class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // multisource bfs
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> rottenOranges;
        int freshOrange = 0;
        int time = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }
        while (!rottenOranges.empty() && freshOrange) {
            cout << freshOrange << " " << time << endl;
            time++;
            vector<pair<int, int>> neighbours = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            int levelSize = rottenOranges.size();
            while (levelSize--) {
                pair<int, int> rotten = rottenOranges.front();
                rottenOranges.pop();
                for (auto neighbour : neighbours) {
                    int row = rotten.first + neighbour.first;
                    int col = rotten.second + neighbour.second;
                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
                        grid[row][col] == 1) {
                        freshOrange--;
                        rottenOranges.push({row, col});
                        grid[row][col] = 2;
                    }
                }
            }
        }
        return freshOrange ? -1 : time;
    }
};