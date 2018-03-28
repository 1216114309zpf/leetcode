class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        
        vector<int> tmp(matrix[0].size(),0);
        vector<vector<int>> heights(matrix.size(),tmp);
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1'){
                    if(i!=0){
                        heights[i][j]=heights[i-1][j]+1;
                    }else{
                        heights[i][j]=1;
                    }
                }else{
                    heights[i][j]=0;
                }
            }
        }
        
        int result=0;
        for(int i=0;i<matrix.size();++i){
            getLargestRectangle(heights[i],result);
        }
        return result;
    }
    
    void getLargestRectangle(vector<int>& heights, int &result){
        stack<int> stk;
        for(int i=0;i<heights.size();++i){
            while(!stk.empty() and heights[i]<heights[stk.top()]){
                int top=stk.top();
                stk.pop();
                result=max(result, heights[top]*(i-(stk.empty()?0:stk.top()+1)));
            }
            stk.push(i);
        }
        
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();
            result=max(result, heights[top]*(heights.size()-(stk.empty()?0:stk.top()+1)));
        }
    }
    
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
};
