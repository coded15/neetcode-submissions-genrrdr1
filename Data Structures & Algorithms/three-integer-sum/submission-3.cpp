class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;
        for(int i = 0; i < nums.size(); i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while(l<r)
            {
                if((nums[l] + nums[r]) == (-1*nums[i]))
                {
                    uniqueTriplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if((nums[l] + nums[r])> (-1*nums[i]))
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};
