class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> myMap;
        for(int i=0;i<strs.size();++i){
            string str=strs[i];
            sort(str.begin(),str.end());
            myMap[str].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto itr=myMap.begin();itr!=myMap.end();++itr){
            result.push_back(itr->second);
        }
        return result;
    }
};
