class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> allowedWords;
        for (auto it : wordList) {
            allowedWords.insert(it);
        }
        if (!allowedWords.count(endWord) || (beginWord.length() != endWord.length())) {
            return 0;
        }
        queue<string> matchedWords;
        matchedWords.push(beginWord);
        allowedWords.erase(beginWord);
        return bfs(endWord, allowedWords, matchedWords);
    }

    int bfs(string endWord, unordered_set<string>& allowedWords, queue<string>& matchedWords) {
        int result = 0;
        while (!matchedWords.empty()) {
            int levelSize = 0;
            levelSize = matchedWords.size();
            result++;
            while (levelSize--) {
                string currentWord = matchedWords.front();
                matchedWords.pop();
                if (currentWord == endWord) {
                    return result;
                }
                for (int i = 0; i < currentWord.size(); i++) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        char temp = currentWord[i];
                        currentWord[i] = j;
                        if (allowedWords.find(currentWord) != allowedWords.end()) {
                            matchedWords.push(currentWord);
                            allowedWords.erase(currentWord);
                        }
                        currentWord[i] = temp;
                    }
                    // cout << temp << " ";
                }
            }
        }
        return 0;
    }
};
