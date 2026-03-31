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
                    // s.erase(idx)             // Erases all characters after idx, so write like below
                    temp_t.erase(pos, 1);
                    if(temp_t.empty())
                    {
                        if(right - left + 1 < minLen) {
                            minLen = right - left + 1;
                            result = s.substr(left, minLen);
                        }
                        // here the left pointer is changed only when one solution is found and then we move on the next left to see the possibility of another minimum length
                        break;
                    }
                }
            }
        }
        return result;
    }
};