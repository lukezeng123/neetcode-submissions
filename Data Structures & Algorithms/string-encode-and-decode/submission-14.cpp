class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string st = "";
            int le = 0;
            while (s[i] != '#') {
                le = le * 10 + (s[i] - '0');
                i++;
            }
            i++;
            while (le--) {
                st += s[i];
                i++;
            }
            res.push_back(st);
        }
        return res;
    }
};
