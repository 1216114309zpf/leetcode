class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int count=0;
        int i=0;
        for(i=0;i<num.size();++i){
            if(stk.empty()){
                stk.push(num[i]);
            }else{
                if(count==k){
                    stk.push(num[i]);
                    continue;
                }
                
                while(!stk.empty() and stk.top()>num[i]){
                    stk.pop();
                    ++count;
                    if(count==k){
                        break;
                    }
                }
                stk.push(num[i]);
            }
        }
        while(count!=k){
            stk.pop();
            ++count;
        }
        string result="";
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        while(result[result.size()-1]=='0')
            result.pop_back();
        reverse(result.begin(),result.end());
        if(result=="")
            result="0";
        return result;
    }
};
