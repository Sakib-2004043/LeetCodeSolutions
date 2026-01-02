class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            int ignore = add(n); // use add() to maintain heap
            // Sorting During Insertion
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop(); // keep only k largest
        }
        return pq.top(); // k-th largest
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */