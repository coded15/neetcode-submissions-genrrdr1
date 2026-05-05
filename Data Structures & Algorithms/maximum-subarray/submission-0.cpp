class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // dont need this condition as it will be handled by below condition itself
            // if(nums[i]<=0 && result<=0)
            // {
            //     continue;
            // }
            if(sum<=0)
            {
                sum = 0;
                // continue;
            }
            sum += nums[i];
            result = max(result, sum);
            // this loop can be avoided, but how?
            // for(int j = i; j < nums.size(); j++)
            // {
            //     sum += nums[j];
            //     result = max(sum, result);
            // }
        }
        return result;
    }
};
