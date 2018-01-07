class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n<1)
            return result;
        
        for(int i=0;i<n;++i){
            vector<int> row;
            for(int j=0;j<n;++j){
                row.push_back(0);
            }
            result.push_back(row);
        }
        
        int left=0;
        int right=n-1;
        int up=0;
        int down=n-1;
        int i=0;
        int j=0;
        int current=1;
        
        while(left<=right and up<=down){
            if(left<=right and up<=down){
                j=up;
                for(i=left;i<=right;++i){
                    result[j][i]=current;
                    ++current;
                }
                ++up;
            }
            
            if(up<=down and left<=right){
                i=right;
                for(j=up;j<=down;++j){
                    result[j][i]=current;
                    ++current;
                }
                --right;
            }
            
            if(left<=right and up<=down){
                j=down;
                for(i=right;i>=left;--i){
                    result[j][i]=current;
                    ++current;
                }
                --down;
            }
            
            if(up<=down and left<=right){
                i=left;
                for(j=down;j>=up;--j){
                    result[j][i]=current;
                    ++current;
                }
                ++left;
            }
        }
        return result;
    }
};
