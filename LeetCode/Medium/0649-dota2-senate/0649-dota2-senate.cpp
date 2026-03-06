class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rad, dir;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            senate[i] == 'R' ? rad.push(i) : dir.push(i);
        }
        while (!rad.empty() && !dir.empty()) {
            if(rad.front() < dir.front()) {
                rad.push(rad.front() + n);
                rad.pop();
                dir.pop();
            }
            else {
                dir.push(dir.front() + n);
                dir.pop();
                rad.pop();
            }
        }
        return rad.size() ? "Radiant" : "Dire";
    }
};