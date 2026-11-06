class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == nums[i]) continue;

                if (nums[j] - nums[i] == 1) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    break;
                }

                if (nums[j] - nums[i] > 1) break;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};