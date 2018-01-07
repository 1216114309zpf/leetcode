class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int *rowSum = new int[matrix.size()];
        int *colSum = new int[matrix[0].size()];
        for(int i=0;i<matrix.size();++i)
            rowSum[i]=0;
        for(int i=0;i<matrix[0].size();++i)
            colSum[i]=0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]!=0)
                    ++rowSum[i];
            }
        }
        for(int i=0;i<matrix[0].size();++i){
            for(int j=0;j<matrix.size();++j){
                if(matrix[j][i]!=0)
                    ++colSum[i];
            }
        }
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(rowSum[i]==matrix[0].size() and colSum[j]==matrix.size())
                    ;
                else
                    matrix[i][j]=0;
            }
        }
        
    }
};
