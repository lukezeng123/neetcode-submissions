class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int cp;
public:
    LRUCache(int capacity) {
        cp = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cp == cache.size()) {
            cache.erase(order.front());
            order.pop_front();
        }
        order.push_back(key);
        cache[key] = {value,--order.end()};

    }
};
