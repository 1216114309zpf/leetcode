class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        if(matrix.size()==0)
            return result;
        vector<int> tmp(matrix[0].size(),-1);
        vector<vector<int>> pacific(matrix.size(),tmp);
        vector<vector<int>> atlantic(matrix.size(),tmp);
        vector<vector<int>> checked(matrix.size(),tmp);
        
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                vector<vector<int>> vec=checked;
                pacific[i][j]=getPacific(pacific,matrix,vec,i,j);
                vector<vector<int>> another=checked;
                atlantic[i][j]=getAtlantic(atlantic,matrix,another,i,j);
                if(pacific[i][j] and  atlantic[i][j]){
                    result.push_back(pair<int,int>(i,j));
                }
            }
        }

        return result;
    }
    
    bool getPacific(vector<vector<int>>&pacific,vector<vector<int>>&matrix,vector<vector<int>>&checked,int row,int col){
        // if(pacific[row][col]!=-1){
        //     return pacific[row][col];
        // }
        
        if(row==0 or col==0){
            return pacific[row][col]=1;
        }
        
        checked[row][col]=1;
        
        if(row-1>=0 and matrix[row][col]>=matrix[row-1][col] and checked[row-1][col]!=1){
            if(getPacific(pacific,matrix,checked,row-1,col)){
                return pacific[row][col]=1;
            }
        }
        
        if(col-1>=0 and matrix[row][col]>=matrix[row][col-1] and checked[row][col-1]!=1){
            if(getPacific(pacific,matrix,checked,row,col-1)){
                return pacific[row][col]=1;
            }
        }
        
        if(row+1<matrix.size() and matrix[row][col]>=matrix[row+1][col] and checked[row+1][col]!=1){
            if(getPacific(pacific,matrix,checked,row+1,col)){
                return pacific[row][col]=1;
            }
        }
        
        if(col+1<matrix[row].size() and matrix[row][col]>=matrix[row][col+1] and checked[row][col+1]!=1){
            if(getPacific(pacific,matrix,checked,row,col+1)){
                return pacific[row][col]=1;
            }
        }
        
        return pacific[row][col]=0;
    }
    
    bool getAtlantic(vector<vector<int>>&atlantic,vector<vector<int>>&matrix,vector<vector<int>>&checked,int row,int col){
        // if(atlantic[row][col]!=-1){
        //     return atlantic[row][col];
        // }
        
        if(row==matrix.size()-1 or col==matrix[row].size()-1){
            return atlantic[row][col]=1;
        }
        
        checked[row][col]=1;
        
         if(row+1<matrix.size() and matrix[row][col]>=matrix[row+1][col] and checked[row+1][col]!=1){
            if(getAtlantic(atlantic,matrix,checked,row+1,col)){
                return atlantic[row][col]=1;
            }
        }
        
        if(col+1<matrix[row].size() and matrix[row][col]>=matrix[row][col+1] and checked[row][col+1]!=1){
            if(getAtlantic(atlantic,matrix,checked,row,col+1)){
                return atlantic[row][col]=1;
            }
        }
        
        if(row-1>=0 and matrix[row][col]>=matrix[row-1][col] and checked[row-1][col]!=1){
            if(getAtlantic(atlantic,matrix,checked,row-1,col)){
                return atlantic[row][col]=1;
            }
        }
        
        if(col-1>=0 and matrix[row][col]>=matrix[row][col-1] and checked[row][col-1]!=1){
            if(getAtlantic(atlantic,matrix,checked,row,col-1)){
                return atlantic[row][col]=1;
            }
        }
        

        return atlantic[row][col]=0;
    }
};
