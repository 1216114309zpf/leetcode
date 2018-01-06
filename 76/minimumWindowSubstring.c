class Solution {
public:
    string minWindow(string s, string t) {
        int *countT=new int[256];
        int *countS=new int[256];
        for(int i=0;i<256;++i){
            countT[i]=0;
            countS[i]=0;
        }
        
        for(int i=0;i<s.size();++i){
            ++countS[s[i]];
        }
        
        for(int i=0;i<t.size();++i){
            ++countT[t[i]];
        }
        
        for(int i=0;i<256;++i){
            if(countS[i]<countT[i])
                return "";
        }
        
        int left=0;
        int right=s.size()-1;
        
        while(true){
            if(countT[s[right]]==0 or countS[s[right]]>countT[s[right]]){
                --countS[s[right]];
                --right;
            }else{
                break;
            }
        }
        while(true){
            if(countT[s[left]]==0 or countS[s[left]]>countT[s[left]]){
                --countS[s[left]];
                ++left;
            }else{
                break;
            }
        }
        
        string result="";
        for(int i=left;i<=right;++i)
            result.push_back(s[i]);
        
        while(true){
            while(right+1<s.size() and s[right+1]!=s[left]){
                ++countS[s[right+1]];
                ++right;
            }
            
            if(right+1==s.size())
                break;
            else{
                ++countS[s[left]];
                ++right;
            }
            
            while(true){
                if(countT[s[left]]==0 or countS[s[left]]>countT[s[left]]){
                   --countS[s[left]];
                    ++left;
                }else{
                   break;
                }
            }
            
            if(right-left+1<result.size()){
                result="";
                for(int i=left;i<=right;++i)
                    result.push_back(s[i]);
            }
        }
        
        return result;
        
    }
};
