class LRUCache {
    int cap;
    std::list<std::pair<int,int>> order;                        // front = most recent
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        order.splice(order.begin(), order, it->second);         // move to front
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if ((int)map.size() == cap) {
            map.erase(order.back().first);
            order.pop_back();
        }
        order.emplace_front(key, value);
        map[key] = order.begin();
    }
};
