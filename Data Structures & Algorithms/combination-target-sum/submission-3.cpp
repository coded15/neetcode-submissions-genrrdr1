class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // map<vector<int>,int> result;
        vector<int> combination;
        vector<vector<int>> uniqueResult;
        dfs(0, target, nums, combination, uniqueResult);   
        // for(auto &it: result)
        // {
        //     uniqueResult.push_back(it.first);
        // }
        return uniqueResult;
    }

    void dfs(int i, int target, vector<int>& nums, vector<int> &combination,vector<vector<int>> &uniqueResult)
    {
        if(target == 0) // this needs to be above the below case
        {
            uniqueResult.push_back(combination);
            return;
        }
        if(target < 0 ||i>=nums.size()) // also have equalty with nums.size()
        {
            return;
        }

        if (nums[i] <= target) {
            combination.push_back(nums[i]);

            dfs(i, target - nums[i], nums, combination, uniqueResult);

            combination.pop_back(); // move inside
        }


        dfs(i+1, target, nums, combination, uniqueResult);
    }
};
