/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<int> s;
        vector<int> e;
        for (auto& v : schedule) {
            for (auto& i : v) {
                s.push_back(i.start);
                e.push_back(i.end);
            }
            
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        vector<Interval> res;
        while (i < s.size() && j < e.size()) {
            if (s[i] < e[j]) {
                cnt++;
                
                i++;
                
            } else if (s[i] > e[j]) {
                cnt--;
                if (cnt == 0) {
                    res.push_back(Interval{e[j],s[i]});
                }
                j++;
            } else {
                i++;
                j++;

            }
        }
        return res;
    }
};
