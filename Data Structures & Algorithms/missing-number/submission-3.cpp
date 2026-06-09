class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int remaining = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i];
            remaining ^= nums[i] ^ i;
        }
        return remaining;
    }
};
