class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        int sa=A.size();
        int sb=B.size();
        
        int count=sb/sa;
        string target="";
        for(int i=0;i<count;++i)
            target+=A;
        if(isSubString(target,B))
            return count;
        target+=A;
        if(isSubString(target,B))
            return count+1;
        target+=A;
        if(isSubString(target,B))
            return count+2;
        return -1;
    }
    
    bool isSubString(string str, string pattern){
        int *next=new int[pattern.size()];
        next[0]=-1;
        for(int i=1;i<pattern.size();++i){
            int k=next[i-1];
            while(k!=-1 and pattern[i-1]!=pattern[k])
                k=next[k];
            next[i]=k+1;
        }
        
        int s=0;
        int p=0;
        while(s<str.size()){
            if(str[s]==pattern[p]){
                ++s;
                ++p;
            }else if(next[p]==-1){
                ++s;
            }else{
                p=0;
            }
            
            if(p==pattern.size())
                return true;
        }
        return false;
    }
};
