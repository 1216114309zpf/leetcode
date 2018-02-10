class Solution {
public:
    string shortestPalindrome(string s) {
        string newS=s+"#";
        string ss=s;
        reverse(ss.begin(),ss.end());
        newS+=ss;
        int *next=new int[newS.size()];
        next[0]=-1;
        for(int i=1;i<newS.size();++i){
            int k=next[i-1];
            while(k!=-1 and newS[i-1]!=newS[k]){
                k=next[k];
            }
            next[i]=k+1;
        }
        int length=0;
        if(newS[newS.size()-1]==newS[next[newS.size()-1]]){
            length=next[newS.size()-1]+1;
        }
        string result="";
        for(int i=s.size()-1;i>=length;--i)
            result.push_back(s[i]);
        result+=s;
        return result;
    }
};
