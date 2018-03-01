class Solution {
public:
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
