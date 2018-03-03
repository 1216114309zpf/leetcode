class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),compare);
        reverse(d.begin(),d.end());
        for(int i=0;i<d.size();++i){
            if(d[i].size()>s.size())
                continue;
            int itrs=0;
            int itrd=0;
            while(itrs!=s.size() and itrd!=d[i].size()){
                if(s[itrs]==d[i][itrd]){
                    ++itrs;
                    ++itrd;
                }else{
                    ++itrs;
                }
            }
            if(itrd==d[i].size()){
                return d[i];
            }
        }
        return "";
    }
    static bool compare(string &a,string &b){
        if(a.size()<b.size()){
            return true;
        }else if(a.size()==b.size()){
            for(int i=0;i<a.size();++i){
                if(a[i]<b[i]){
                    return false;
                }else{
                    return true;
                }
            }
        }else{
            return false;
        }
        return true;
    }
};
