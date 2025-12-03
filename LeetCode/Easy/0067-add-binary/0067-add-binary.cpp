class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry, i, n;
        n = max(a.size(), b.size());
        if (a.size() < b.size()) {
            swap(a, b);
        }
        n = a.size();

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        carry = 0;
        for (i = 0; i < n; i++) {
            int ai, bi, sum;
            ai = int(a[i]) - '0';
            if (i < b.size()) {
                bi = int(b[i]) - '0';
            } else {
                bi = 0;
            }
            sum = ai + bi + carry;
            if (sum == 3) {
                result += '1';
                carry = 1;
            } else if (sum == 2) {
                result += '0';
                carry = 1;
            } else if (sum == 1) {
                result += '1';
                carry = 0;
            } else {
                result += '0';
                carry = 0;
            }
        }
        if (carry) {
            result += '1';
        }
        reverse(result.begin(), result.end());

        return result;
    }
};