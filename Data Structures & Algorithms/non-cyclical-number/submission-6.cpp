class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        int fast = sumOfSquares(n);
        int slow = n;
        

        while (fast != slow) {
            fast = sumOfSquares(sumOfSquares(fast));
            slow = sumOfSquares(slow);
            if (slow == 1 || fast == 1) {
                return true;
            }
        }
        return false;
    }

private:
    int sumOfSquares(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
    }
};
