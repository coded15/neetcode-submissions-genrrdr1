class Solution {
public:
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> state; // 0 = unvisited, 1 = visiting, 2 = visited
    string ans;

    bool dfs(char c) {
        if (state[c] == 1) return false; // cycle
        if (state[c] == 2) return true;  // already processed

        state[c] = 1;

        for (char nei : adj[c]) {
            if (!dfs(nei))
                return false;
        }

        state[c] = 2;
        ans += c;

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        // Add every character as a node
        for (string &word : words) {
            for (char c : word)
                adj[c];
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string &w1 = words[i];
            string &w2 = words[i + 1];

            int len = min(w1.size(), w2.size());

            // Invalid prefix case
            if (w1.size() > w2.size() &&
                w1.substr(0, len) == w2.substr(0, len))
                return "";

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }

        // Topological sort
        for (auto &p : adj) {
            if (state[p.first] == 0) {
                if (!dfs(p.first))
                    return "";
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};