/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    class mycompare {
    public:
        bool operator()(const Interval& a, const Interval& b) {
            if (a.start != b.start) return a.start < b.start;
            else return a.end < b.end;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), mycompare());
        vector<Interval> result;
        for (const Interval& i : intervals) {
            if (result.empty()) {
                result.push_back(i);
            } else {
                if (i.start > result.back().end) {
                    result.push_back(i);
                } else {
                    if (i.end > result.back().end) {
                        result.back().end = i.end;
                    }
                }
            }
        }
        return result;
    }
};
