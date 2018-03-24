class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        vector<int> tmp(matrix[0].size(),-1);
        vector<vector<int>> result(matrix.size(),tmp);
        int longest=-1;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                int var=recursive(matrix,result,i,j);
                if(longest<var){
                    longest=var;
                }
            }
        }
        return longest;
    }
    
    int recursive(vector<vector<int>>& matrix, vector<vector<int>>&result, int row, int col){
        if(result[row][col]!=-1){
            return result[row][col];
        }
        
        
        int left,right,up,down;
        if(row==0 or matrix[row-1][col]<=matrix[row][col]){
            up=0;
        }else{
            up=recursive(matrix,result,row-1,col);
        }
        
        if(row==matrix.size()-1 or matrix[row+1][col]<=matrix[row][col]){
            down=0;
        }else{
            down=recursive(matrix,result,row+1,col);
        }
        
        if(col==0 or matrix[row][col-1]<=matrix[row][col]){
            left=0;
        }else{
            left=recursive(matrix,result,row,col-1);
        }
        
        if(col==matrix[0].size()-1 or matrix[row][col+1]<=matrix[row][col]){
            right=0;
        }else{
            right=recursive(matrix,result,row,col+1);
        }
                                                     
        return result[row][col]=max(up,down,left,right)+1;
    }
    int max(int a,int b,int c,int d){
        if(a>b){
            return max(a,c,d);
        }else{
            return max(b,c,d);
        }
    }
    int max(int a,int b,int c){
        if(a>b){
            if(a>c){
                return a;
            }else{
                return c;
            }
        }else{
            if(b>c){
                return b;
            }else{
                return c;
            }
        }
    }
};
