class KthLargest {
public:
    vector<int> nums; // descending order
    int k;

    KthLargest(int k, vector<int>& arr) {
        this->k = k;
        for (int val : arr) {
            add(val); // reuse add() safely
        }
    }

    int add(int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (val > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        nums.insert(nums.begin() + left, val); // insert in descending order

        // Only return k-th largest if we have enough elements
        if (nums.size() >= k)
            return nums[k - 1];
        else
            return nums.back(); // return largest available for now
    }
};
