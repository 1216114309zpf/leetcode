class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solved(board);
    }
    
    bool solved(vector<vector<char>>& board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]=='.'){
                    for(int k='1';k<='9';++k){
                        if(feasible(board,i,j,k)){
                            board[i][j]=k;
                            if(solved(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool feasible(vector<vector<char>>& board, int i,int j,char k){
        for(int p=0;p<9;++p){
            if(board[i][p]==k)
                return false;
            if(board[p][j]==k)
                return false;
        }
        for(int t=i/3*3;t<i/3*3+3;++t){
            for(int p=j/3*3;p<j/3*3+3;++p){
                if(board[t][p]== k)
                    return false;
            }
        }
        return true;
    }
};
