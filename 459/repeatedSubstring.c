oclass Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str="";
        for(int i=0;i<s.size()/2;++i){
            str.push_back(s[i]);
            if(s.size()%str.size()==0){
               if(repeated(s,str))
                    return true;
            }
        }
        return false;
    }
    
    bool repeated(string s,string str){
        string tmp="";
        for(int i=0;i<s.size()/str.size();++i){
            tmp+=str;
        }
        if(tmp==s)
         return true;
        else
            return false;
    }
};
