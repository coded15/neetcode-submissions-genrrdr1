class Solution {
   public:
    int findMaxVal(vector<int>& nums, int left, int right) {
        int maxVal = INT_MIN;
        for (int i = left; i <= right; i++) {
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if (nums.size() == k) {
        //     vector<int> result;
        //     result.push_back(findMaxVal(nums, 0, k - 1));
        //     return result;
        // }
        int maxVal = findMaxVal(nums, 0, k - 1);
        nums[0] = maxVal;
        for (int l = 1, r = k; r < nums.size(); l++, r++) {
            if (nums[r] >= maxVal) {
                maxVal = nums[r];
            } else {
                maxVal = findMaxVal(nums, l, r);
            }
            nums[l] = maxVal;
        }
        vector<int> result(nums.begin(), nums.begin() + nums.size() - k + 1);
        return result;
    }
};
