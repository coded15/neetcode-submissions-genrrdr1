// Read its binary search one pass algortithm

class Solution {
public:
// Their were two edge cases that I missed totally, that I should keep in mind everytime I deal with 2D matrix ever again
// 1) what if it is a 1D row
// 2) what if it has only one entry
// 3) what if it is null
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int topRow = 0, bottomRow = m -1;
        int targetRow = 0;
        while(topRow <= bottomRow)
        {
            if(topRow==bottomRow){
                targetRow = topRow;
                break;
            }
            int midRow = (topRow + bottomRow)/2;
            int midValue = matrix[midRow][0];
            if(target == midValue)
            {
                return true;
            }
            // if(target > matrix[topRow][0] && target < matrix[topRow+1][0])
            // {
            //     targetRow = topRow;
            //     break;
            // }
            if(target > (midValue) && target <= matrix[midRow][n-1])
            {
                targetRow = midRow;
                break;
            }
            else if(target > midValue)
            {
                topRow = midRow+1;
            }
            else if(target < midValue)
            {
                bottomRow = midRow-1;
            }
        }
        int left = 0;
        int right = n -1;
        while(left <= right)
        {
            int leftValue = matrix[targetRow][left];
            int rightValue = matrix[targetRow][right];
            if(left==right)
            {
                if(target==rightValue)
                {
                    return true;
                }
                return false;
            }
            int mid = (left+right)/2;
            int midValue = matrix[targetRow][mid];
            if(midValue == target)
            {
                return true;
            }
            if(midValue>target)
            {
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }

        }
        return false;
    }
};
