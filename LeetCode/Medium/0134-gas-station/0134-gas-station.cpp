class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0; // total gas - cost
        int tank = 0;  // current tank
        int start = 0; // candidate start index
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1; // cannot start anywhere before this
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
