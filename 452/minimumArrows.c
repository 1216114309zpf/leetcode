class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),compare);
        int result=0;
        int current=0;
        while(current<points.size()){
            ++result;
            int tmp=current;
            while(current<points.size() and points[current].first<=points[tmp].second)
                ++current;
        }
        return result;
    }
    
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
};
