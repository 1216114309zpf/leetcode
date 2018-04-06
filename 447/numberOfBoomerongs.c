class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int,int> tmp;
        vector<unordered_map<int,int>> array(points.size(),tmp);
        for(int i=0;i<points.size();++i){
            for(int j=0;j<i;++j){
                int distanceS=pow(points[i].first-points[j].first,2)+pow(points[i].second-points[j].second,2);
                if(array[i].count(distanceS)==0){
                    array[i][distanceS]=1;
                }else{
                    ++array[i][distanceS];
                }
                if(array[j].count(distanceS)==0){
                    array[j][distanceS]=1;
                }else{
                    ++array[j][distanceS];
                }
            }
        }
        int result=0;
        for(int i=0;i<array.size();++i){
            for(auto itr=array[i].begin();itr!=array[i].end();++itr){
                result+=(itr->second-1)*(itr->second);
            }
        }
        return result;
    }
};
