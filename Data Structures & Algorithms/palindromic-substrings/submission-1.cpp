class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        int palindromes = n;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    if (isPalindrome(s.substr(i, j - i + 1))) {
                        // cout << s.substr(i, j - i + 1);
                        palindromes++;
                    }
                }
            }
        }
        return palindromes;
    }

    bool isPalindrome(string s) {
        int n = s.size();

        int mid = (n - 1) / 2;

        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) {
                if (s[mid - i] != s[mid + i + 1]) {
                    return false;
                }
            }
        } else {
            for (int i = 0; i < n / 2; i++) {
                if (s[mid - i - 1] != s[mid + i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
