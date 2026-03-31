class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int result = 0;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];
        if(height.size()<=2) return 0;
        while(left < right)
        {
            if(maxLeftHeight <= maxRightHeight)
            {
                left++;
                maxLeftHeight = max(maxLeftHeight, height[left]);
                result += maxLeftHeight - height[left];
            }
            else
            {
                right--;
                maxRightHeight = max(maxRightHeight, height[right]);
                result += maxRightHeight - height[right] ;
            }
        }
        // int left = 0, right = 0, result = 0, maxLeftHeight = 0, maxRightHeight = 0;
        // for(int i = 1; i < height.size(); i++)
        // {
        //     if(height[i] >= height[left] && right == 0)
        //     {
        //         left = i;
        //         maxLeftHeight = height[i];
        //         continue;
        //     }
        //     // else continue;
        //     // for(int k = left + 1; k < height.size();k++)
        //     // {
        //     else if(height[i] >= height[left] && i > left + 1)
        //     {
        //         right = i;
        //         maxRightHeight = height[i];
        //     }
        //     // }
        //     int removal = 0;
        //     for(int j = left + 1; j < right; j++)
        //     {
        //         removal += height[j];
        //     }
        //     result += (min(maxRightHeight, maxLeftHeight)*(right - left - 1))-removal;
        //     left = 0;
        //     maxLeftHeight = 0;
        //     maxRightHeight = 0;
        //     right = 0;
        // }
        return result;
    }
};
