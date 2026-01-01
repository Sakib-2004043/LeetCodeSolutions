class RandomizedSet {
private:
    set<int> rst;

public:
    RandomizedSet() { rst = set<int>(); }

    bool insert(int val) {
        if (rst.count(val)) {
            return false;
        }
        rst.insert(val);
        return true;
    }

    bool remove(int val) {
        if (!rst.count(val)) {
            return false;
        }
        rst.erase(val);
        return true;
    }

    int getRandom() {
        vector<int> v(rst.begin(), rst.end());
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */