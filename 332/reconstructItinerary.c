class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,vector<string>> mymap;
        unordered_map<string,int> exist;
        for(int i=0;i<tickets.size();++i){
            mymap[tickets[i].first].push_back(tickets[i].second);
            string str=tickets[i].first;
            str+=tickets[i].second;
            if(exist.count(str)==0){
                exist[str]=1;
            }else{
                exist[str]++;
            }
        }
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr){
            sort(itr->second.begin(),itr->second.end());
        }
        
        vector<string> result;
        result.push_back("JFK");
        help(mymap,exist,"JFK",result,tickets.size()+1,1);
        return result;
    }   
    
    bool help(unordered_map<string,vector<string>>&mymap,unordered_map<string,int>&exist,string current, vector<string>&result, int size,int cnt){
        if(cnt==size){
            return true;
        }
        
        for(int i=0;i<mymap[current].size();++i){
            string item=current;
            item+=mymap[current][i];
            if(exist[item]>0){
                exist[item]--;
                result.push_back(mymap[current][i]);
                if(help(mymap,exist,mymap[current][i],result,size,cnt+1)){
                    return true;
                }
                result.pop_back();
                exist[item]++;
            }
        }
        return false;
    }
};
