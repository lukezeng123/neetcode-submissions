class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') t.push(c);
            if (c == ')' || c == '}' || c == ']') {
                if (!t.empty()) {
                    char b = t.top();
                    t.pop();
                    if (c == ')' && b == '(') continue;
                    if (c == '}' && b == '{') continue;
                    if (c == ']' && b == '[') continue;
                    return false;
                } else return false; 
            } 
        }
        return t.empty();
    }
};
