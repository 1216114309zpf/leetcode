/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()==0)
            return 0;
        int result=0;
        unordered_map<long double,int> cnt;
        vector<unordered_map<long double,int>> matrix(points.size(),cnt);
        
        for(int i=0;i<points.size();++i){
            matrix[i][INT_MIN]=0;
            for(int j=0;j<i;++j){
                if(points[i].x==points[j].x and points[i].y==points[j].y){
                    ++matrix[i][INT_MIN];
                    ++matrix[j][INT_MIN];
                    if(matrix[i][INT_MIN]>result){
                        result=matrix[i][INT_MIN];
                    }
                    
                    if(matrix[j][INT_MIN]>result){
                        result=matrix[j][INT_MIN];
                    }
                    
                    continue;
                }
                int diffx=points[j].x-points[i].x;
                int diffy=points[j].y-points[i].y;
                if(diffx==0){
                    matrix[i][INT_MAX]++;
                    if(matrix[i][INT_MAX]+matrix[i][INT_MIN]>result){
                        result=matrix[i][INT_MAX]+matrix[i][INT_MIN];
                    }
                    matrix[j][INT_MAX]++;
                    if(matrix[j][INT_MAX]+matrix[j][INT_MIN]>result){
                        result=matrix[j][INT_MAX]+matrix[j][INT_MIN];
                    }
                }else{
                    long double ratio=(long double)(diffy)/diffx;
                    matrix[i][ratio]++;
                    matrix[j][ratio]++;
                    
                    if(matrix[i][ratio]+matrix[i][INT_MIN]>result)
                        result=matrix[i][ratio]+matrix[i][INT_MIN];
                    
                    if(matrix[j][ratio]+matrix[j][INT_MIN]>result)
                        result=matrix[j][ratio]+matrix[j][INT_MIN];
                }
            }
        }
        return result+1;
    }
};
