class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        int minLen = INT_MAX;
        for(int left = 0; left < s.size(); left++)
        {
            string temp_t = t;
            for(int right = left; right < s.size(); right++)
            {
                size_t pos = temp_t.find(s[right]);
                if(pos != string::npos)
                {
                    temp_t.erase(pos, 1);
                    if(temp_t.empty())
                    {
                        if(right - left + 1 < minLen) {
                            minLen = right - left + 1;
                            result = s.substr(left, minLen);
                        }
                        break;
                    }
                }
            }
        }
        return result;
    }
};