class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            if ((a >> i) & 1 && (b >> i) & 1) {
                ans |= (carry << i);
                carry = 1;
            } else {
                if (((a >> i) & 1 || (b >> i) & 1) && carry) continue;
                ans |= ((((a >> i) & 1 || (b >> i) & 1) || carry) << i);
                carry = 0;
            }
        }
        return ans;
    }
};
