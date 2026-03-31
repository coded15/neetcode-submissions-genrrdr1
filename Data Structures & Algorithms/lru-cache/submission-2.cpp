class LRUCache {
public:
int capacity = 0;
int currentSize =0;
int time = 0;
unordered_map<int, pair<int, int>> keyValueWithTime;
    LRUCache(int capacity) {
        // somehow I have to figure out how to sort the data structure based on count, without using count as the key, as otherwise the get or put operation where I have to look for a key are going to nearly impossible
        this->capacity = capacity;
        // priority_queue<pair<int, pair<int, int>>> keyValueWithCount; // <count, <key, value>>
        // priority_queue<ListNode* > count; not possible because we want get and put to be of O(1) time complexity, which is only possible with map. BTW how much is the time complexity of find function on a heap, does heap even have that?

    }
    
    int get(int key) {
        if (keyValueWithTime.find(key) == keyValueWithTime.end()) {
            return -1;
        }
        keyValueWithTime[key].second = ++time;
        return keyValueWithTime[key].first;
    }

    void put(int key, int value) {
        // to check if the key is there or not while putting, you cant use get because that will update the time state
        if (keyValueWithTime.find(key) != keyValueWithTime.end()) {
            keyValueWithTime[key] = {value, ++time};
            return;
            // cant update the current size if the key is already there but just being updated.
        }

        if (currentSize == capacity) {
            // cannot dangerously initialize oldest key as 0, what if that key is not even there in map. And on top of that when in the below if condition I call keyValueWithTime[oldestKey] it will insert that key with some garbage value and I wouldnt no about that, as it will lead to no runtime error
            auto it = keyValueWithTime.begin();
            int oldestKey = it->first;

            for (auto &p : keyValueWithTime) {
                if (p.second.second < keyValueWithTime[oldestKey].second) {
                    oldestKey = p.first;
                }
            }

            keyValueWithTime.erase(oldestKey);
            currentSize--;
        }

        keyValueWithTime[key] = {value, ++time};
        currentSize++;
    }
};
