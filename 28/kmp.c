class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size()==0)
            return -1;
        int *next=new int[needle.size()];
        next[0]=-1;
        for(int i=1;i<needle.size();++i){
            int k=next[i-1];
            while(k!=-1 and needle[k]!=needle[i-1]){
                k=next[k];
            }
            next[i]=k+1;
        }
        
        int h=0;
        int n=0;
        while(h<haystack.size()){
            if(haystack[h]==needle[n]){
                ++n;
                ++h;
            }else{
                if(next[n]==-1){
                    ++h;
                    n=0;
                }else if(next[n]==0){
                    n=0;
                }else{
                    n=next[n];
                }
            }
            if(n==needle.size())
                return h-n;
            if(h==haystack.size())
                return -1;
        }
        
        
    }
};
