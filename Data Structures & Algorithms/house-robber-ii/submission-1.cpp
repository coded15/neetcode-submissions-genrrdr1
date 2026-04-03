class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int n = nums.size();
        // removing the first element
        int two = nums[n-1];
        int one = max(nums[n-2], two);
        for(int i = n - 3; i >=1; i--)
        {
            int temp = one;
            one = max((nums[i]+two), temp);
            two = temp;
        }
        int maxWithOutFirst = one;
        // removing the last element
        two = nums[n-2];
        one = max(nums[n-3], two);
        for(int i = n - 4; i >=0; i--)
        {
            int temp = one;
            one = max((nums[i]+two), temp);
            two = temp;
        }
        return max(maxWithOutFirst, one);
    }
};
