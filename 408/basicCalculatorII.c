class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        tokens=parse(s);
        stack<string> stk;
        vector<string> newTokens;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i][0]>='0' and tokens[i][0]<='9'){
                newTokens.push_back(tokens[i]);
                while(!stk.empty() and (stk.top()=="*" or stk.top()=="/")){
                    newTokens.push_back(stk.top());
                    stk.pop();
                }
            }else{
                if(tokens[i]=="+" or tokens[i]=="-"){
                    while(!stk.empty() and (stk.top()=="+" or stk.top()=="-")){
                        newTokens.push_back(stk.top());
                        stk.pop();
                    }
                }
                stk.push(tokens[i]);
            }
        }
        while(!stk.empty()){
            newTokens.push_back(stk.top());
            stk.pop();
        }
        return evalRPN(newTokens);
    }
    
    vector<string> parse(string str){
        vector<string> result;
        for(int i=0;i<str.size();++i){
            string tmp="";
            if(str[i]==' '){
                continue;
            }else if(str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/'){
                tmp.push_back(str[i]);
                result.push_back(tmp);
            }else{
                while(str[i]>='0' and str[i]<='9'){
                    tmp.push_back(str[i]);
                    ++i;
                }
                --i;
                result.push_back(tmp);
            }
        }
        return result;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i][0]>='0' and tokens[i][0]<='9' or tokens[i].size()>1){
                stk.push(toInt(tokens[i]));
            }else{
                int a=stk.top();
                stk.pop();
                int b=stk.top();
                stk.pop();
                if(tokens[i]=="+"){
                    b+=a;
                }else if(tokens[i]=="-"){
                    b-=a;
                }else if(tokens[i]=="*"){
                    b*=a;
                }else{
                    b/=a;
                }
                stk.push(b);
            }
        }
        return stk.top();
    }
    int toInt(string str){
        int result=0;
        int flag=0;
        if(str[0]=='-'){
            flag=-1;
        }else{
            flag=1;
        }
        for(int i=(flag==1)?0:1; i<str.size();++i){
            result*=10;
            result+=(str[i]-'0');
        }
        return result*flag;
    }
    
};
