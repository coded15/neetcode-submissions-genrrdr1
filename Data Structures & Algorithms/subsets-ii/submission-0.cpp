class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        vector<int> currentSubset;
        dfs(0, nums, output, currentSubset);
        return output;
    }

    void dfs(int i, vector<int>& nums, vector<vector<int>>& output, vector<int>& currentSubset) {
        if (i == nums.size()) {
            output.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(nums[i]);
        dfs(i + 1, nums, output, currentSubset);
        currentSubset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        dfs(i + 1, nums, output, currentSubset);
    }
};
