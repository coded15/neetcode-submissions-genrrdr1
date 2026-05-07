class Solution {
public:
    int jump(vector<int>& nums) {
        int last = nums.size() - 1;
        nums[last] = 0;
        for(int i = last - 1; i >=0; i--)
        {
            if(nums[i]==0)
            {
                nums[i] = INT_MAX;
            }
            else if(last - i <=nums[i])
            {
                nums[i]=1;
            }
            else
            {
                int l = i+1;
                int r = nums[i] + i;
                int minJumps = INT_MAX;
                for(int j = l; j <=r; j++)
                {
                    minJumps = min(minJumps, nums[j]);
                }
                nums[i]=minJumps+1;
            }
        }
        return nums[0];
    }
};
