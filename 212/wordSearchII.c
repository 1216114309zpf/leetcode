class Solution {
    struct Node{
        bool word;
        string str;
        Node*array[26];
        Node(){
            word=false;
            str="";
            for(int i=0;i<26;++i)
                array[i]=NULL;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node*root=new Node();
        //insertion
        for(int i=0;i<words.size();++i){
            Node*ptr=root;
            for(int j=0;j<words[i].size();++j){
                if(ptr->array[words[i][j]-'a']==NULL){
                    ptr->array[words[i][j]-'a']=new Node();
                }
                ptr=ptr->array[words[i][j]-'a'];
            }
            ptr->word=true;
            ptr->str=words[i];
        }
        
        vector<string> result;
        unordered_map<string,bool> mymap;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                vector<bool> tmp(board[0].size(),false);
                vector<vector<bool>> matrix(board.size(),tmp);
                if(root->array[board[i][j]-'a']!=NULL)
                     backtrack(board,result,matrix,root->array[board[i][j]-'a'],i,j,mymap);
            }
        }
        
        return result;
    }
    
    void backtrack(vector<vector<char>>&board, vector<string>& result, vector<vector<bool>>&matrix, Node*root,int row, int col,unordered_map<string,bool>&mymap){
        if(root->word){
            if(mymap.count(root->str)==0){
                result.push_back(root->str);
                mymap[root->str]=true;
            }
        }
        matrix[row][col]=true;
        //up
        if(row!=0 and matrix[row-1][col]==false and root->array[board[row-1][col]-'a']!=NULL){
            backtrack(board,result,matrix,root->array[board[row-1][col]-'a'],row-1,col,mymap);
        }
        
        //down
        if(row!=matrix.size()-1 and matrix[row+1][col]==false and root->array[board[row+1][col]-'a']!=NULL){
            backtrack(board,result,matrix,root->array[board[row+1][col]-'a'],row+1,col,mymap);
        }
        
        //left
        if(col!=0 and matrix[row][col-1]==false and root->array[board[row][col-1]-'a']!=NULL){
            backtrack(board,result,matrix,root->array[board[row][col-1]-'a'],row,col-1,mymap);
        }
        
        //right
        if(col!=matrix[0].size()-1 and matrix[row][col+1]==false and root->array[board[row][col+1]-'a']!=NULL){
            backtrack(board,result,matrix,root->array[board[row][col+1]-'a'],row,col+1,mymap);
        }
        matrix[row][col]=false;
    }
};
