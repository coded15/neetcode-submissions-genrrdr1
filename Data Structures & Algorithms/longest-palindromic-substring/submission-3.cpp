class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();

        pair<string, int> maxLength = {s.substr(0, 1), 1};

        for (int i = 0; i < n; i++) {

            int j = n - 1;

            while (j >= i) {

                // only proceed if chars match
                if (s[i] == s[j]) {

                    string substring = s.substr(i, j - i + 1);

                    if (isPalindrome(substring)) {

                        if (substring.length() > maxLength.second) {

                            maxLength.first = substring;
                            maxLength.second = substring.length();
                        }
                    }
                }

                j--;
            }
        }

        return maxLength.first;
    }

    bool isPalindrome(string s) {

        int n = s.length();

        for (int i = 0; i < n / 2; i++) {

            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};