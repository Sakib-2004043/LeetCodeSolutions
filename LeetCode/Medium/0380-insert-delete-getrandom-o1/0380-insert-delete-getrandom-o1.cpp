class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> index;

public:
    bool insert(int val) {
        if (index.count(val))
            return false;

        data.push_back(val);
        index[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!index.count(val)) {
            return false;
        }

        int idx = index[val];
        int lastVal = data.back();

        // Move last element to idx
        data[idx] = lastVal;
        index[lastVal] = idx;

        // Remove last element
        data.pop_back();
        index.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % data.size();
        return data[randomIndex];
    }
};
