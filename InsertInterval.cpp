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
    int findIndex(vector<Interval> const &intervals, int num, bool& o_exists)
    {
        int lo = 0;
        int hi = intervals.size() - 1;
        
        while (lo <= hi)
        {
            auto mid = (lo + hi) / 2;

            if (num > intervals[mid].end)
                lo = mid + 1;
            else if (num < intervals[mid].start)
                hi = mid - 1;
            else
            {
                o_exists = true;
                return mid;
            }
        }
        
        o_exists = false;
        return lo;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        bool eLo = false;
        int lo = findIndex(intervals, newInterval.start, eLo);
        bool hiLo = false;
        int hi = findIndex(intervals, newInterval.end, hiLo);
        
        Interval newI = newInterval;
        int hewHi = 0;
        
        if (eLo && hiLo)
        {
            newI.start = intervals[lo].start;
            newI.end = intervals[hi].end;
            hewHi = hi + 1;
        }
        else if (!eLo && !hiLo)
        {
            hewHi = hi;
        }
        else if (eLo && !hiLo)
        {
            newI.start = intervals[lo].start;
            hewHi = hi;
        }
        else
        {
            newI.end = intervals[hi].end;
            hewHi = hi + 1;
        }
        
        if (lo < intervals.size())
        {
            intervals[lo] = newI;
            intervals.erase(intervals.begin() + lo + 1, intervals.begin() + hewHi);
        }
        else
           intervals.push_back(newI);
        
        
        return intervals;
    }
};