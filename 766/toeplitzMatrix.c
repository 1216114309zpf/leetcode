class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return true;
        for(int i=0;i<matrix.size();++i){
            int number=matrix[i][0];
            int j=1;
            while(i+j<matrix.size() and j<matrix[0].size()){
                if(number!=matrix[i+j][j])
                    return false;
                ++j;
            }
        }
        for(int i=0;i<matrix[0].size();++i){
            int number=matrix[0][i];
            int j=1;
            while(j<matrix.size() and i+j<matrix[0].size()){
                if(number!=matrix[j][i+j])
                    return false;
                ++j;
            }
        }
        return true;
    }
};
