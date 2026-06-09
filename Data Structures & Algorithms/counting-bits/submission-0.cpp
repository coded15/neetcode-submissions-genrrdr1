class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int j = 0; j <= n; j++) {
            int count = 0;
            for (int i = 0; i < 32; i++) {
                if ((1 << i) & j) {
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};
