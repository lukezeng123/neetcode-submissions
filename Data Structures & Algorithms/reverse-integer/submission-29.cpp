class Solution {
public:
    int reverse(int x) {
        // if (x == 0) return 0;
        // const int MIN = -2147483648; // -2^31
        // const int MAX = 2147483647;  // 2^31 - 1
        // string smin = to_string(MIN);
        // smin = string(smin.begin() + 1, smin.end());
        // string smax = to_string(MAX);
        // string s = to_string(x);
        // vector<char> rev;

        // for (int i = s.size() - 1; i >= 0; --i) {
        //     if (s[i] != '-') rev.push_back(s[i]);
        // }
        // while (rev[0] == 0) {
        //     rev.erase(rev.begin());
        // }
        // if (rev.size() > 10) return 0;
        // if (rev.size() < 10) {
        //     if (x > 0) {
        //         return stoi(string(rev.begin(), rev.end()));
        //     } else {
        //         return -stoi(string(rev.begin(), rev.end()));
        //     }

        // }
        // if (x > 0) {
        //     for (int i = 0; i < 10; i++) {
        //         if (rev[i] > smax[i]) return 0;
        //         if (rev[i] > smin[i]) break;
        //     }
        //     return stoi(string(rev.begin(), rev.end()));
        // } else {
        //     cout << "hi4" << endl;
        //     for (int i = 0; i < 10; i++) {
        //         cout << rev[i] << " "<< smin[i] << endl;

        //         if (rev[i] > smin[i]) return 0;
        //         if (rev[i] < smin[i]) break;

        //     }
        //     return -stoi(string(rev.begin(), rev.end()));
        // }

        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // Check for overflow before we append digit:
            if (result >  INT_MAX/10 || (result ==  INT_MAX/10 && digit >  7)) return 0;
            if (result <  INT_MIN/10 || (result ==  INT_MIN/10 && digit < -8)) return 0;
            result = result * 10 + digit;
        }
        return result;
        // int result = 0;
        // while (x != 0) {
        //     int digit = x % 10;
        //     x %= 10;
        //     x /= 10;
        //     if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7 )) return 0;
        //     if (result < INT_MIN/10 || (result == INT_MIN/10 && digit < -8)) return 0;
        // }
        // return result;
    }
};
