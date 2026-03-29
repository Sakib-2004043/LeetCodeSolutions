class EventManager {
public:
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq;

    EventManager(vector<vector<int>>& events) {
        for (auto& e : events) {
            int id = e[0], p = e[1];
            mp[id] = p;
            pq.push({p, -id});
        }
    }

    void updatePriority(int eventId, int priority) {
        mp[eventId] = priority;
        pq.push({priority, -eventId});
    }

    int pollHighest() {
        while (!pq.empty()) {
            auto [p, negId] = pq.top();
            pq.pop();
            int id = -negId;
            if (mp.count(id) && mp[id] == p) {
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */