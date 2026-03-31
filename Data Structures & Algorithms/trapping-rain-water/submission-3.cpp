class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int result = 0;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];
        if(height.size()<=2) return 0;
        // while(left < right)
        // {
        //     if(maxLeftHeight <= maxRightHeight)
        //     {
        //         left++;
        //         maxLeftHeight = max(maxLeftHeight, height[left]);
        //         result += maxLeftHeight - height[left];
        //     }
        //     else
        //     {
        //         right--;
        //         maxRightHeight = max(maxRightHeight, height[right]);
        //         result += maxRightHeight - height[right] ;
        //     }
        // }
        for(int i = 0; i < height.size() && left < right; i++)
        {
            int temp = 0;
            // this can't depend on generic height index of i, but is right is being removed reduce the right pointer and if left is being increased increase the left pointer
            // int temp = min(maxLeftHeight, maxRightHeight) - height[i];
            // result += (temp > 0 ? temp : 0);
            if(maxLeftHeight <= maxRightHeight)
            {
                temp = min(maxLeftHeight, maxRightHeight) - height[left];
                
                left++;
                maxLeftHeight = max(maxLeftHeight, height[left]);
            }
            else
            {
                temp = min(maxLeftHeight, maxRightHeight) - height[right];
                right--;
                maxRightHeight = max(maxRightHeight, height[right]);
            }
            result += (temp > 0 ? temp : 0);
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
