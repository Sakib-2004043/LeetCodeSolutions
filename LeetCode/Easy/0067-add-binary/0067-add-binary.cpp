class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int n = max(a.size(), b.size());

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            int bitA = (i < a.size()) ? a[i] - '0' : 0;
            int bitB = (i < b.size()) ? b[i] - '0' : 0;

            int sum = bitA + bitB + carry;
            result += (sum % 2) + '0';  // sum bit
            carry = sum / 2;             // carry for next iteration
        }

        if (carry) result += '1';

        reverse(result.begin(), result.end());
        return result;
    }
};
