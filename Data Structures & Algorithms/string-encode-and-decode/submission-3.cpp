class Solution {
   public:
    string encode(vector<string>& strs) {
        string res;
        for (auto str : strs) {
            res += to_string(str.size()) + ',';
        }
        res += '#';
        for (auto str : strs) {
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        int stringStart;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                stringStart = i + 1;
                break;
            }
            for (int j = i; j < s.size(); j++) {
                if (s[j] == ',') {
                    sizes.push_back(stoi(s.substr(i, j - i)));
                    i = j;
                    break;
                }
            }
        }
        vector<string> result;
        for (int i = 0; i < sizes.size(); i++) {
            result.push_back(s.substr(stringStart, sizes[i]));
            stringStart += sizes[i];
        }
        return result;
    }
};
