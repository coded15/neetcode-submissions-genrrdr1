class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int l = 0, r = 1;
        int length = s.size();
        unordered_map <char, int> count_char;
        count_char[s[l]]++;
        int res = 1;
        int current_length = 1;
        for(;l<length && l < r && r < length;)
        {
            if(count_char[s[r]]==0){
            count_char[s[r]]++;
            r++;
            current_length++;
            res = max(res, current_length);
            }
            else
            {
                l++;
                r = l+1;
                //pop all elements in count_char;
                count_char.clear();
                count_char[s[l]]++;
                current_length = 1;
            }
        }
        return res;
    }
};
