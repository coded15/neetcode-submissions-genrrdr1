class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        while(left >=0 && right < nums.size() && right >= left)
        {
            mid = (left + right)/2;
            // if(nums[left] == target)
            // {
            //     return left;
            // }
            // if(nums[right] == target)
            // {
            //     return right;
            // }
            if(target==nums[mid])
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
