/*
LRUCache: Least Recently Used Cache
- Supports get(key) and put(key,value) in O(1) time
- Evicts the least recently used item when capacity is exceeded

Key Idea:
- Use a doubly linked list (list) to maintain order of usage:
    front = most recently used
    back  = least recently used
- Use an unordered_map to quickly find a key's position in the list
*/

class LRUCache {
private:
    int capacity; // Maximum number of items cache can hold

    // Doubly linked list to store (key, value) pairs in usage order
    // Front = most recently used, Back = least recently used
    list<pair<int, int>> cache;

    // Map: key -> iterator pointing to its node in the list
    // Using iterator allows O(1) access, erase, and update in the list
    unordered_map<int, list<pair<int, int>>::iterator> pos;

public:
    // Constructor: initialize LRU cache with given capacity
    LRUCache(int capacity) { this->capacity = capacity; }

    // Get value by key
    int get(int key) {
        // Key not found → return -1
        if (pos.find(key) == pos.end()) {
            return -1;
        }
        // Key exists → get value using iterator
        // pos[key] is an iterator pointing to the node in the list
        int value = pos[key]->second;

        // Move the accessed node to the front of the list (most recently used)
        // Step 1: remove it from current position
        cache.erase(pos[key]);
        // Step 2: insert at front
        cache.push_front({key, value});

        // Step 3: update the iterator in the map to new position
        pos[key] = cache.begin();

        return value;
    }

    // Put key-value pair into cache
    void put(int key, int value) {

        // Case 1: Key already exists → update value and move to front
        if (pos.find(key) != pos.end()) {
            // Remove the old node from the list
            cache.erase(pos[key]);
        }
        // Case 2: Key does not exist and cache is full → evict LRU item
        else if (cache.size() == capacity) {
            // Back of the list = least recently used
            auto last = cache.back();
            // Remove it from map
            pos.erase(last.first);
            // Remove it from list
            cache.pop_back();
        }

        // Insert the new (or updated) key-value pair at the front (most recent)
        cache.push_front({key, value});
        // Update map with iterator pointing to the new front node
        pos[key] = cache.begin();
    }
};
