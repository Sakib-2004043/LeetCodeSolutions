class KthLargest {
public:
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        this->nums = nums;
        this->k = k;
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
        nums.insert(nums.begin() + left, val);
        return nums[k - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */