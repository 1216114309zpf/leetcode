class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mymap;
        for(int i=0;i<words.size();++i){
            ++mymap[words[i]];
        }
        vector<pair<string, int>> elems(mymap.begin(), mymap.end());
        sort(elems.begin(),elems.end(),compare);
        vector<string> result;
        int count=0;
        for(auto itr=elems.begin();itr!=elems.end();++itr){
            result.push_back(itr->first);
            ++count;
            if(count==k)
                break;
        }
        return result;
    }
    
    static bool compare(pair<string,int> &a,pair<string,int> &b){
        if(a.second>b.second){
            return true;
        }else if(a.second==b.second){
            if(a.first>b.first){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
};
