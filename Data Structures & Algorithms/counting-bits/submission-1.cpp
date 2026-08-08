class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            int num = i;
            while(num)
            {
                result[i]++;
                num &= (num-1);
            }
        }
        return result;
    }
};
