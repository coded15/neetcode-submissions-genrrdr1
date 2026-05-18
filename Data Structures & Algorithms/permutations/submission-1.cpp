class Solution {
   public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        vector<int> current;
        permutation(nums, current, seen);
        return result;
    }

    void permutation(vector<int>& nums, vector<int>& current, vector<bool>& seen) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!seen[i]) {
                current.push_back(nums[i]);
                seen[i] = true;
                permutation(nums, current, seen);
                current.pop_back();
                seen[i] = false;
                // permutation(nums, current, seen); will lead to infinite recursive calling
            }
        }
    }
};
