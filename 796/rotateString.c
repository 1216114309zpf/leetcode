class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size())
            return false;
        vector<int> next(B.size());
        next[0]=-1;
        
        for(int i=1;i<B.size();++i){
            int tmp=next[i-1];
            while(tmp!=-1 and B[tmp]!=B[i-1]){
                tmp=next[tmp];
            }
            next[i]=tmp+1;
        }
        
        string str=A+A;
        int a=0;
        int b=0;
        while(a<str.size() and b<B.size()){
            if(str[a]==B[b]){
                ++a;
                ++b;
            }else{
                if(next[b]==-1){
                    b=0;
                    ++a;
                }else{
                    b=next[b];
                }
            }
        }
        
        if(b==B.size()){
            return true;
        }
        
        return false;
    }
};
