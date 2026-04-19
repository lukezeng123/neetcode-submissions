class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (left.empty() && star.empty()) return false;
                if (left.empty()) star.pop();
                else left.pop();
            }
        }

        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        if (!left.empty()) return false;
        return true;
    }

};
