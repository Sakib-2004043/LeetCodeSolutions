class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<bool> isExisting;

public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            minHeap.push(i);
        }
        isExisting.assign(1005, true);
    }
    int popSmallest() {
        int num = minHeap.top();
        minHeap.pop();
        isExisting[num] = false;
        return num;
    }
    void addBack(int num) {
        if (!isExisting[num]) {
            minHeap.push(num);
        }
        isExisting[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */