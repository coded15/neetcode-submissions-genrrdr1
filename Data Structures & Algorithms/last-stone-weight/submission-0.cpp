class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        while(n>1)
        {
            if(stones[n-1]==stones[n-2])
            {
                stones.pop_back();
                stones.pop_back();
                n -=2;
            }
            else
            {
                stones[n-2] = stones[n-1]-stones[n-2];
                stones.pop_back();
                --n;
                sort(stones.begin(), stones.end());
            }
        }
        return ((n==1)?stones[0]:0);    
    }
};
