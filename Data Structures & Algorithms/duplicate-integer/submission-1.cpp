class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count_num;
        for(int i = 0; i < nums.size(); i++)
        {
            count_num[nums[i]]++;
        }
        if(count_num.size() < nums.size())
        {
            return true;
        }
        return false;
    }
};