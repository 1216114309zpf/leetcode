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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> vecEnd;
        for(int i=0;i<schedule.size();++i){
            for(int j=0;j<schedule[i].size();++j){
                vecEnd.push_back(schedule[i][j]);
            }
        }
        sort(vecEnd.begin(),vecEnd.end(),compareEnd);
        vector<Interval> result;
        
        int end=vecEnd[0].end;
        for(int i=1;i<vecEnd.size();++i){
            if(vecEnd[i].start<=end){
                end=vecEnd[i].end;
            }else{
                int start=100000000;
                for(int j=i;j<vecEnd.size();++j){
                    if(vecEnd[j].start<end){
                        start=end;
                        break;
                    }
                    else{
                        if(vecEnd[j].start<start)
                            start=vecEnd[j].start;
                    }
                }
                if(start!=end and start!=100000000){
                    Interval tmp(end,start);
                    result.push_back(tmp);
                }
                end=vecEnd[i].end;
            }
        }
        return result;
    }
    
    static bool compareEnd(Interval a,Interval b){
        return a.end<b.end;
    }
    static bool compareStart(Interval a,Interval b){
        return a.start<b.start;
    }
};
