class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = squareSum(n);

        while (fast != 1 && slow != fast) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return fast == 1;
    }
};
