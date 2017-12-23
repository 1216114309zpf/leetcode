class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        string result = "";
        string current= "";
        for(int i=0; i<words.size(); ++i){
            if(isPrefix(current, words[i])){
                current = words[i];
                if(current.size() > result.size())
                    result = current;
            }else if(current == words[i]){
                continue;
            }else{
                current = common(current, words[i]);
                if(current.size() > result.size())
                    result = current;
            }
        }
        return result;
    }
    
    static bool compare(string &a, string &b){
        int la = a.size();
        int lb = b.size();
        int l=(la>lb)?lb:la;
        for(int i=0;i<l;++i){
            if(a[i]<b[i])
                return true;
            if(a[i]>b[i])
                return false;
        }
        
        if(la < lb)
            return true;
        else
            return false;
    }
    
    bool isPrefix(string a, string b){
        if(b.size() - a.size() != 1)
            return false;
        for(int i=0; i<a.size(); ++i){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    string common(string current, string str){
        string result = "";
        int lc = current.size();
        int ls = str.size();
        int l=(lc<ls)?lc:ls;
        int i;
        for(i=0; i<l; ++i){
            if(current[i] == str[i])
                result.push_back(current[i]);
            else
                break;
        }
        if(i<ls and i<lc)
            result.push_back(str[i]);
        return result;
    }
};
