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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size()<2)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int count=0;
        int end=intervals[0].end;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start>=end){
                end=intervals[i].end;
            }else{
                ++count;
            }
        }
        return count;
    }
    
    static bool compare(Interval a,Interval b){
        return a.end<b.end;
    }
};
