class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i, n;
        n = tokens.size();
        for (i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int x = stoi(tokens[i - 2]);
                int y = stoi(tokens[i - 1]);
                int z = 0;
                if (tokens[i] == "+") {
                    z = x + y;
                } else if (tokens[i] == "-") {
                    z = x - y;
                } else if (tokens[i] == "*") {
                    z = x * y;
                } else if (tokens[i] == "/") {
                    z = x / y;
                }
                tokens[i - 2] = to_string(z);
                tokens.erase(tokens.begin() + i);
                tokens.erase(tokens.begin() + i - 1);
                i = 0;
            }
        }
        return stoi(tokens[0]);
    }
};