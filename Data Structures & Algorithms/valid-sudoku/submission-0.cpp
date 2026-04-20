class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int row)
    {
        unordered_map<int, int> count;
        for(int i = 0; i < 9; i++)
        {
            count[board[row][i]]++;
            if(board[row][i] != '.' && count[board[row][i]]>1)
            {
                cout << "row";
                return false;
            }
        }
        return true;
    }
    bool checkColumn(vector<vector<char>>& board, int column)
    {
       unordered_map<int, int> count;
        for(int i = 0; i < 9; i++)
        {
            count[board[i][column]]++;
            if(board[i][column] != '.' && count[board[i][column]]>1)
            {
                cout << "column";
                return false;
            }
        }
        return true;
    }
    bool checkBoxes(vector<vector<char>>& board, int row, int column)
    {
        unordered_map<int, int> count;
        for(int i = row; i < row + 3; i++)
        {
            for(int j = column; j< column + 3; j++)
            {
                count[board[i][j]]++;
                if(board[i][j] != '.' && count[board[i][j]]>1)
                {
                    cout << "box" << row << " " << column << " "<<i << j;
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            if(!checkRow(board, i))
            {
                cout << "row";
                return false;
            }
        }
        for(int i = 0; i < 9; i++)
        {
            if(!checkColumn(board, i))
            {
                cout << "column";
                return false;
            }
        }
        for(int i = 0; i < 9; i = i + 3)
        {
            for(int j = 0; j < 9; j = j + 3)
            {
                if(!checkBoxes(board, i , j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
