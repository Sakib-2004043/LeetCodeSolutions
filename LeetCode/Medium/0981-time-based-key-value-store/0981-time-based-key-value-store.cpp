class TimeMap {
private:
    unordered_map<string, map<int, string>> timeMap;

public:
    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto ub = timeMap[key].upper_bound(timestamp);
        if (ub != timeMap[key].begin()) {
            return prev(ub)->second;
        } else {
            return "";
        }
    }
};

/*
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */