class Solution {
public:
    bool isScramble(string s1, string s2) {
        string tmp1=s1;
        string tmp2=s2;
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());
        if(tmp1!=tmp2){
            return false;
        }
        return isSubScramble(s1,s2);
    }
    
    bool isSubScramble(string s1,string s2){
        if(s1.size()!=s2.size()){
            return false;
        }
        
        if(s1==s2){
            return true;
        }
        
        for(int i=0;i<s1.size()-1;++i){
            string s1_left(s1,0,i+1);
            string s1_right(s1,i+1,s1.size()-i-1);
            string s2_left(s2,0,i+1);
            string s2_right(s2,i+1,s2.size()-i-1);
            
            string tmp1l=s1_left;
            string tmp1r=s1_right;
            string tmp2l=s2_left;
            string tmp2r=s2_right;
            sort(tmp1l.begin(),tmp1l.end());
            sort(tmp1r.begin(),tmp1r.end());
            sort(tmp2l.begin(),tmp2l.end());
            sort(tmp2r.begin(),tmp2r.end());
            
            if(tmp1l==tmp2l){
                if(isSubScramble(s1_left,s2_left) and isSubScramble(s1_right,s2_right)){
                    return true;
                }
            }
            
            string s2r(s2,s2.size()-i-1,i+1);
            string s2l(s2,0,s2.size()-i-1);
            string tmpl=s2l;
            string tmpr=s2r;
            sort(tmpr.begin(),tmpr.end());
            sort(tmpl.begin(),tmpl.end());
            if(tmp1l==tmpr){
                if(isSubScramble(s1_right,s2l) and isSubScramble(s1_left,s2r)){
                    return true;
                }
            }
        }
        return false;
    }
};
