class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_map<string,int> myMap;
        queue<string> que;
        que.push(s);
        que.push("-");
        while(!que.empty()){
            string str=que.front();
            que.pop();
            if(result.size()!=0){
                if(str=="-")
                    return result;
                if(isValid(str)){
                    //cout<<str<<endl;
                    result.push_back(str);
                }
                continue;
            }
            if(str=="-"){
                if(!que.empty() and result.size()==0){
                    que.push("-");
                }else{
                    return result;
                }
            }else{
                if(isValid(str)){
                    result.push_back(str);
                    continue;
                }
                for(int i=0;i<str.size();++i){
                    if(str[i]>='a' and str[i]<='z' or str[i]>='A' and str[i]<='Z'){
                        continue;
                    }
                    string tmp=str;
                    tmp.erase(tmp.begin()+i);
                    if(myMap.count(tmp)==0){
                        myMap[tmp]=1;
                        que.push(tmp);
                    }
                }
            }
        }
        return result;
    }
    
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();++i){
            if(s[i]>='a' and s[i]<='z' or s[i]>='A' and s[i]<='Z'){
                continue;
            }
            if(stk.empty()){
                stk.push(s[i]);
            }else{
                if(s[i]=='('){
                    stk.push(s[i]);
                }else{
                    if(s[i]==')'){
                        if(stk.top()!='('){
                            return false;
                        }else{
                            stk.pop();
                        }
                    }
                }
            }
        }
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};
