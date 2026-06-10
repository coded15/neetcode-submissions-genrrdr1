class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int sum = 0;
        while (sum != 1 || n != 0) {
            if (seen.find(n) != seen.end()) {
                return false;
            }
            if (n == 0) {
                seen.insert(sum);
                n = sum;
                sum = 0;
            }
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return true;
    }
};
