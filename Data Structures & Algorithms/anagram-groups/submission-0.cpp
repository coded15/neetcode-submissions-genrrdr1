class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> anagram;
        for(const auto& it:strs)
        {
            string temp_copy = it;
            sort(temp_copy.begin(),temp_copy.end());
            anagram[temp_copy].push_back(it);
        }
        vector<vector<string>> result;
        for(const auto& it: anagram)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
