class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, n, ans;
        n = height.size();
        ans = 0;
        for (i = 0, j = n - 1; i != j;) {
            int area = (j - i) * min(height[i], height[j]);
            ans = max(ans, area);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};