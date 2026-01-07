class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> key;
        set<int> ans;
        vector<bool> visited(rooms.size(), false);
        ans.insert(0);
        key.push(0);
        visited[0] = true;
        while (!key.empty()) {
            for (auto x : rooms[key.front()]) {
                if (!visited[x]) {
                    key.push(x);
                    visited[x] = true;
                }
            }
            ans.insert(key.front());
            key.pop();
        }
        return rooms.size() == ans.size();
    }
};