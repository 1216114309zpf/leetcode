class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if(grid.size()<2)
            return 0;
        if(grid[0].size()<2)
            return 0;
        int ** array = new int*[grid.size()];
        for(int i=0; i<grid.size(); ++i){
            array[i] = new int[grid[0].size()];
            for(int j=0; j<grid[0].size(); ++j)
                array[i][j] = 0;
        }
        
        for(int i=1; i<grid.size(); ++i){
            for(int j=1; j<grid[0].size(); ++j){
                int tmp = array[i-1][j] + array[i][j-1] - array[i-1][j-1];
                if(grid[i][j]==0){
                    array[i][j] = tmp;
                    continue;
                }
                int increment = 0;
                for(int k=0; k<i; ++k){
                    if(!grid[k][j])
                        continue;
                    for(int l=0; l<j; ++l){
                        if(grid[k][l] and grid[i][l])
                            ++increment;
                    }
                }
                array[i][j] = tmp + increment;
            }
        }
        return array[grid.size()-1][grid[0].size()-1]  ;
    }
};
