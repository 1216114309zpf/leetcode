class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, bool> exist;
        unordered_map<string, bool> contained;
        int result=0;
        sort(words.begin(),words.end(),compare);
        for(int i=0;i<words.size();++i){
            reverse(words[i].begin(),words[i].end());
        }
        string last=words[words.size()-1];
        for(int i=0;i<words.size();++i)
            exist[words[i]]=true;
        for(int i=0;i<words.size();++i){
            if(contained.count(words[i])==0){
                result+=words[i].size();
                result++;
            }
            contained[words[i]]=true;
            
            string tmp=words[i];
            while(words[i].size()){
                words[i].pop_back();
                if(exist.count(words[i])!=0){
                    contained[words[i]]=true;
                    break;
                }
            }
        }
        
        
        return result;
    }
    
    static bool compare(string &a,string &b){
        return a.size()>b.size();
    }
};
