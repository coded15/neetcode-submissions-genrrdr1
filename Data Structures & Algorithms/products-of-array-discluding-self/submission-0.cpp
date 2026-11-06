class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // without using division operator
        // O(n) time complexity
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = 1;
        suffix[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
