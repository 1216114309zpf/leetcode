class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool> mymap;
        for(int i=0;i<words.size();++i){
            mymap[words[i]]=true;
        }
        
        vector<string> result;
        for(int i=0;i<words.size();++i){
            if(cancatenated(mymap,words[i],0)){
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
    
    bool cancatenated(unordered_map<string,bool>&mymap,string str,int position){
        string s="";
        for(int i=position;i<str.size();++i){
            s.push_back(str[i]);
            if(mymap.count(s)!=0){
                if(i==str.size()-1){
                    if(position==0){
                        return false;
                    }else{
                        return true;
                    }
                }else{
                    if(cancatenated(mymap,str,i+1))
                        return true;
                }
            }
        }
        return false;
    }
};
