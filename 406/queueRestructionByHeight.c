class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        if(people.size()==0)
            return result;
        sort(people.begin(),people.end(),compare);
        result.push_back(people[0]);
        int count=1;
        for(int i=1;i<people.size();++i){
            if(people[i].first==people[0].first){
                result.push_back(people[i]);
                ++count;
            }
            else break;
        }
        for(int i=count;i<people.size();++i){
            result.insert(result.begin()+people[i].second,people[i]);
        }
        return result;
    }
    
    static bool compare(pair<int,int> a, pair<int,int> b){
        if(a.first<b.first){
            return false;
        }else if(a.first==b.first){
            if(a.second<b.second)
                return true;
            else
                return false;
        }else{
            return true;
        }
    }
};
