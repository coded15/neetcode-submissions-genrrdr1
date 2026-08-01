class Solution {
   public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(const string& s, const vector<string>& wordSet, int i) {
        // if (i == s.size()) {
        //     return true;
        // }
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        // for (int j = i; j < s.size(); j++) {
        //     if (wordSet.find(s.substr(i, j - i + 1)) != wordSet.end()) {
        //         if (dfs(s, wordSet, j + 1)) {
        //             return true;
        //         }
        //     }
        // }
        for (const string& word : wordSet) {
            if (((i + word.length()) <= s.length()) && (s.substr(i, word.length()) == word)
                // (memo.find(i + word.size()) != memo.end())
                // in each iteration, a true result should be decided by whether the current word is
                // matching the substring not whether its memo is true, because thats we are trying
                // to construct, not the other way around
            ) {
                if (dfs(s, wordSet, i + word.length())) {
                    // memo[i + word.length()] = true;
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false; // you will have to explicitly mark this as false, as this is a map, and it doesn't have s.length() entries inserted and intialized to false by default, we are inserting keys step by setp as we compute.
        return false;
    }
};