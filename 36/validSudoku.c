class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool *array=new bool[9];
        clearfy(array);
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.' and array[board[i][j]-'0'-1]){
                    return false;
                }else{
                    if(board[i][j]!='.')
                         array[board[i][j]-'0'-1]=true;
                }
            }
            clearfy(array);
            for(int j=0;j<9;++j){
                if(board[j][i]!='.' and array[board[j][i]-'0'-1]){
                    return false;
                }else{
                    if(board[j][i]!='.')
                        array[board[j][i]-'0'-1]=true;
                }
            }
            clearfy(array);
        }
        
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                for(int k=0;k<3;++k){
                    for(int l=0;l<3;++l){
                        if(board[i*3+k][j*3+l]!='.' and array[board[i*3+k][j*3+l]-'0'-1]){
                              return false;
                        }else{
                              if(board[i*3+k][j*3+l]!='.')
                                   array[board[i*3+k][j*3+l]-'0'-1]=true;
                        }
                    }
                }
                clearfy(array);
            }
        }
        return true;
    }
    
    void clearfy(bool array[]){
        for(int i=0;i<9;++i)
            array[i]=false;
    }
};
