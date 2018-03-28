class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0)
            return 0;
        stack<int> stk;
        
        int result=0;
        int i=0;
        for(i=0;i<heights.size();++i){
            while(!stk.empty() and heights[i]<heights[stk.top()]){
                int top=stk.top();
                stk.pop();
                result=max(result, heights[top]*(i-(stk.empty()?0:(stk.top()+1))));
            }
            stk.push(i);
        }
        
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();
            result=max(result, heights[top]*(i-(stk.empty()?0:(stk.top()+1))));
        }
        return result;
    }
};
