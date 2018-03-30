class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mymap;
        for(int i=0;i<wordDict.size();++i)
            mymap[wordDict[i]]=true;
        
        vector<int> array(s.size(),-1);
        help(array,mymap,s,0);
        return array[0];
    }
    
    bool help(vector<int>& array, unordered_map<string,bool>& mymap, string s, int current){
        if(array[current]!=-1){
            return array[current];
        }
        
        string str="";
        for(int i=current;i<s.size();++i){
            str.push_back(s[i]);
            if(mymap.count(str)!=0){
                if(i==s.size()-1){
                    return array[current]=1;
                }else{
                    if(help(array,mymap,s,i+1)){
                        return array[current]=1;
                    }
                }
            }
        }
        
        return array[current]=0;
    }
};
