class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int total =0;
        for(int i=0;i<wall[0].size();++i)
            total+=wall[0][i];
        
        bool flag = false;
        
        vector<int> sum;
        for(int i=0; i<wall.size();++i){
            int subsum=0;
            for(int j=0;j<wall[i].size();++j){
                if(j>0)
                    flag=true;
                subsum+=wall[i][j];
                sum.push_back(subsum);
            }
        }
        sort(sum.begin(),sum.end());
        int same=0;
        
        int current=1;
        for(int i=1;i<sum.size();++i){
            if(sum[i]==sum[i-1]){
                ++current;
                if(current>same and sum[i]!=total)
                    same=current;
            }else{
                current=1;
            }
        }
        
        if(same==0){
            if(flag)
                return wall.size()-1;
        }
        return wall.size()-same;
    }
};
