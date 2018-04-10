class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,vector<int>> mymap;
        unordered_map<int,bool> checked;
        unordered_map<int,bool> busChecked;
        for(int i=0;i<routes.size();++i){
            for(int j=0;j<routes[i].size();++j){
                mymap[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> stations;
        int result=0;
        stations.push(S);
        stations.push(-1);
        checked[S]=true;
        while(!stations.empty()){
            int stop=stations.front();
            stations.pop();
            if(stop==-1){
                if(stations.empty()){
                    return -1;
                }else{
                    ++result;
                    stations.push(-1);
                }
            }else{
                if(stop==T){
                    return result;
                }else{
                    for(int i=0;i<mymap[stop].size();++i){
                        if(busChecked.count(mymap[stop][i])!=0){
                            continue;
                        }
                        for(int j=0;j<routes[mymap[stop][i]].size();++j){
                            if(checked.count(routes[mymap[stop][i]][j])==0){
                                stations.push(routes[mymap[stop][i]][j]);
                                checked[routes[mymap[stop][i]][j]]=true;
                            }
                        }
                        busChecked[mymap[stop][i]]=true;
                    }
                }
            }
        }
        return -1;
    }
};
