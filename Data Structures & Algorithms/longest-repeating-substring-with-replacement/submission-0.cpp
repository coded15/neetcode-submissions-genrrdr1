class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequencyCounter;
        int l = 0;
        int result = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            frequencyCounter[s[r]]++;
            maxf = max(maxf, frequencyCounter[s[r]]);
            if (r - l + 1 - maxf > k) {
                frequencyCounter[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
