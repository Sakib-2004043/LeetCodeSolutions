class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, n, k;
        n = nums.size();
        map<int,bool> visited;
        for (i = 0, k = 0; i < n; i++) {
            nums[k] = nums[i];
            if (!visited[nums[i]]) {
                visited[nums[i]] = true;
                k++;
            }
        }
        return k;
    }
};