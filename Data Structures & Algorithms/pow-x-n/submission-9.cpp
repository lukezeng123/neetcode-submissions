class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }
        double res = 1;
        long long power = abs((long long)n);
        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
            
        }
        if (n < 0) {
            return 1 / res;
        }
        return res;
    }
    
};
