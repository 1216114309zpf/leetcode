class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        stk.push(preorder[0]);
        for(int i=1;i<preorder.size();++i){
            if(preorder[i]==',')
                continue;
            stk.push(preorder[i]);
            while(preorder[i]>='0' and preorder[i]<='9')
                ++i;
            while(stk.size()>=3 and stk.top()=='#'){
                stk.pop();
                char a=stk.top();
                stk.pop();
                char b=stk.top();
                stk.pop();
                if(a=='#'){
                    if(b=='#')
                        return false;
                    else
                        stk.push('#');
                }else{
                    stk.push(b);
                    stk.push(a);
                    stk.push('#');
                    break;
                }
            }
            
        }
        if(stk.size()==1 and stk.top()=='#')
            return true;
        else
            return false;
    }
};
