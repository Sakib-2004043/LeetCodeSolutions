class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> bfsQ;
        int n = board.size();
        int ans = 0;
        reverse(board.begin(), board.end());
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                reverse(board[i].begin(), board[i].end());
            }
        }
        vector<int> jump(n * n + 1, 0);
        for (int i = 0, k = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                jump[k] = (board[i][j] != -1) ? board[i][j] : k;
                k++;
            }
        }
        vector<bool> visited(n * n + 5, false);
        bfsQ.push(jump[1]);
        while (!bfsQ.empty()) {
            int sz = bfsQ.size();
            ans++;
            while (sz--) {
                int num = bfsQ.front();
                bfsQ.pop();
                for (int i = num + 1; i <= num + 6; i++) {
                    int nextCell = jump[i];
                    if (nextCell == n * n) {
                        return ans;
                    }
                    if (nextCell < n * n && !visited[nextCell]) {
                        bfsQ.push(nextCell);
                        visited[nextCell] = true;
                    }
                }
            }
        }
        return -1;
    }
};