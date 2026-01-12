class Solution {
private:
    bool ans = false;
    vector<bool> visited;
    void dfs(auto& arr, int idx) {
        if(arr[idx] == 0){
            ans = true;
        }
        if (visited[idx]) {
            return;
        }
        visited[idx] = true;
        if (idx + arr[idx] < arr.size()) {
            dfs(arr, idx + arr[idx]);
        }
        if (idx - arr[idx] >= 0) {
            dfs(arr, idx - arr[idx]);
        }
    }

public:
    bool canReach(vector<int>& arr, int start) {
        visited.assign(arr.size(), false);
        dfs(arr, start);
        return ans;
    }
};