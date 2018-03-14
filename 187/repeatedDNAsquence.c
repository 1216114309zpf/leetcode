class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> myMap;
        int size=s.size();
        for(int i=0;i<=size-10;++i){
            string str="";
            for(int j=i;j<i+10;++j){
                str.push_back(s[j]);
            }
            if(myMap.count(str)==0){
                myMap[str]=1;
            }else{
                ++myMap[str];
            }
        }
        
        vector<string> result;
        for(auto itr=myMap.begin();itr!=myMap.end();++itr){
            if(itr->second>1){
                result.push_back(itr->first);
            }
        }
        return result;
    }
};
