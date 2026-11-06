class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());   // O(nlogn)
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == 1) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    break;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
