class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0; // storing the global maximum
        for(auto num: numSet)
        {
            if(!numSet.count(num - 1)) // meaning it is the starting number of the sequence
            {
                int length = 1;
                while(numSet.count(num + length)) // checking how many consecutive numbers are present
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
