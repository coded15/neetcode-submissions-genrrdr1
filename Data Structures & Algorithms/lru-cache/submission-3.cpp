class LRUCache {
    int capacity;
    unordered_map<int, pair<int, int>> cache;  //{key, value}
    int currentTime = 0;
    // priority_queue<vector<int>, vector<vector<int>>, [](vector<int>& a, vector<int>&b){return
    // (a[1]>b[1])}; {key, count}
// ahh read the question carefully they are talking about the least recently used key not the least frequently used key
   public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        currentTime++;
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        cache[key].second = currentTime;
        return cache[key].first;
    }

    void put(int key, int value) {
        currentTime++;
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            cache[key].second = currentTime;  // dont forget this
            return;
        }
        if (cache.size() == capacity) {
            // remove the least used key
            int lastUsedTime = currentTime;
            int lastUsedKey;
            for (auto it : cache) {
                if (it.second.second <= lastUsedTime) {
                    lastUsedKey = it.first;
                    lastUsedTime = it.second.second;
                }
            }
            cache.erase(lastUsedKey);
        }
        cache[key] = {value, currentTime};
    }
};
