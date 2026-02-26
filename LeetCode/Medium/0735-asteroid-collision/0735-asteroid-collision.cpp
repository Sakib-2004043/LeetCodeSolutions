class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> ans;
        for (auto ast : asteroids) {
            while (!ans.empty() && ast < 0 && ans.back() > 0) {
                if(abs(ast) == ans.back()){
                    ans.pop_back();
                    goto last;
                }
                else if (abs(ast) > ans.back()) {
                    ans.pop_back();
                } else {
                    goto last;
                }
            }
            ans.push_back(ast);
        last:;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};