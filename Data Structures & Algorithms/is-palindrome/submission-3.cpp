class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        for(; l<r; l++, r--)
        {
            if(!alphaNum(s[l]))
            {
                while(!alphaNum(s[l]))
                {

                    l++;
                }
            }
            if(!alphaNum(s[r]))
            {
                while(!alphaNum(s[r]))
                {

                    r--;
                }
            }
            cout << s[l] << " " << s[r] << endl;
            if(tolower(s[l])!=tolower(s[r])&&l<=r)
            {
                return false;
            }
        }
        return true;
    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
