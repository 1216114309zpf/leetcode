class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0)
            return result;
        int left=0;
        int right=matrix[0].size()-1;
        int up=0;
        int down=matrix.size()-1;
        int i=left;
        int j=up;
        while(left<=right and up<=down){
            if(left<=right and up<=down){
                j=up;
                for(i=left;i<=right;++i){
                    result.push_back(matrix[j][i]);
                }
                ++up;
            }
            
            if(up<=down and left<=right){
                i=right;
                for(j=up;j<=down;++j){
                    result.push_back(matrix[j][i]);
                }
                --right;
            }
            
            if(left<=right and up<=down){
                j=down;
                for(i=right;i>=left;--i){
                    result.push_back(matrix[j][i]);
                }
                --down;
            }
            
            if(up<=down and left<=right){
                i=left;
                for(j=down;j>=up;--j){
                    result.push_back(matrix[j][i]);
                }
                ++left;
            }
        }
        
        return result;
    }
};
