class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        for (int i = 0; i < words.size(); i++) {
            for (const char& ch : words[i]) {
                adjList[ch];
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int word1Size = words[i].size();
            int word2Size = words[i + 1].size();
            if (word1Size > word2Size) {
                if (words[i].substr(0, word2Size) == words[i + 1]) {
                    return "";
                }
            }
            int minSize = min(word1Size, word2Size);
            for (int j = 0; j < minSize; j++) {  // size bounded by word2
                if (words[i][j] != words[i + 1][j]) {
                    adjList[words[i][j]].push_back(words[i + 1][j]);
                    break;  // missed
                }
            }
        }
        string result;
        unordered_set<char> cycle;
        unordered_set<char> visited;
        for (auto it : adjList) {
            if (!dfs(it.first, result, cycle, visited, adjList)) {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool dfs(char ch, string& result, unordered_set<char>& cycle, unordered_set<char>& visited,
             unordered_map<char, vector<char>>& adjList) {
        if (cycle.find(ch) != cycle.end()) {
            return false;
        }
        if (visited.count(ch)) {
            return true;
        }
        cycle.insert(ch);
        for (const char& c : adjList[ch]) {
            if (!dfs(c, result, cycle, visited, adjList)) {
                return false;
            }
        }
        result.push_back(ch);
        visited.insert(ch);
        cycle.erase(ch);
        return true;
    }
};
