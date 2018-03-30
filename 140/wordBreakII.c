class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mymap;
        for(int i=0;i<wordDict.size();++i){
            mymap[wordDict[i]]=true;
        }
        
        vector<string> tmp;
        tmp.push_back("");
        vector<vector<string>> array(s.size(),tmp);
        
        vector<string> result=help(mymap,array,0,s);

        if(result[0]=="-"){
            result.clear();
            return result;
        }else{
            return result;
        }
  }
    
    vector<string> help(unordered_map<string,bool>&mymap, vector<vector<string>>& array, int current,string &s){
        if(array[current][0]!=""){
            return array[current];
        }
        
        array[current].clear();
        string str="";
        for(int i=current;i<s.size();++i){
            str.push_back(s[i]);
            if(mymap.count(str)!=0){
                if(i==s.size()-1){
                    string tmp=" "+str;
                    if(current==0){
                        array[current].push_back(str);
                    }else{
                        array[current].push_back(tmp);
                    }
                }else{
                    vector<string> vec=help(mymap,array,i+1,s);
                    if(vec[0]!="-"){
                        for(int p=0;p<vec.size();++p){
                            if(current==0){
                                array[current].push_back(str+vec[p]);
                            }else{
                                array[current].push_back(" "+str+vec[p]);
                            }
                        }
                    }
                }
                
            }
        }
        
        if(array[current].size()==0){
            array[current].push_back("-");
        }
        
        return array[current];
        
    }
};
