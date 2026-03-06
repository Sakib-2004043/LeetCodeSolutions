class Solution {
public:
    string predictPartyVictory(string senate) {
        int N = 1e4;
        queue<int>rad, dir;
        for (int i = 0; i < senate.size(); i++) {
            senate[i] == 'R' ? rad.push(i) : dir.push(i);
        }
        while (!rad.empty() && !dir.empty()) {
            if(rad.front() < dir.front()) {
                rad.push(rad.front() + N);
                rad.pop();
                dir.pop();
            }
            else {
                dir.push(dir.front() + N);
                dir.pop();
                rad.pop();
            }
        }
        return rad.size() ? "Radiant" : "Dire";
    }
};

// RR