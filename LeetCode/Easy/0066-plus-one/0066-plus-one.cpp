class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] != 9) {
            digits[digits.size() - 1]++;
        } else {
            int k = 1;
            for (int i = digits.size() - 1; i >= 0; i--) {
                if(digits[i] == 9){
                    digits[i]=0;
                }
                else{
                    digits[i]++;
                    k=0;
                    break;
                }
            }
            if(k){
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};