/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { 
            return x.start < y.start; 
        });
        int s = 1e9;
        int e = -1;
        for (Interval i : intervals) {
            s = i.start;
            if (e > s) {
                return false;
            }
            e = i.end;

        }
        return true;
    }
};
