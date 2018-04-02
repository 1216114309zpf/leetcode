class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<int> shots;
        shots.push_back(intervals[0][1]-1);
        shots.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();++i){
            int first=shots[shots.size()-2];
            int second=shots[shots.size()-1];
            if(first>=intervals[i][0]){
                continue;
            }else{
                if(second>=intervals[i][0]){
                    shots.push_back(intervals[i][1]);
                }else{
                    shots.push_back(intervals[i][1]-1);
                    shots.push_back(intervals[i][1]);
                }
            }
        }
        return shots.size();
    }
    
    static bool compare(vector<int> a,vector<int> b){
        if(a[1]<b[1])
            return true;
        else if(a[1]==b[1]){
            return a[0]>b[0];
        }else
            return false;
    }
};
