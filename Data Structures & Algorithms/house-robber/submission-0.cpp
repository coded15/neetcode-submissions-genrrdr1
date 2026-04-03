class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int two = nums[n-1];
        int one = max(nums[n-2], two);
        for(int i = n - 3; i >=0; i--)
        {
            int temp = one;
            one = max((nums[i]+two), temp);
            two = temp;
        }
        return one;
    }
};
