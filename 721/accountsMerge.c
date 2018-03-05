class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> vec;
        for(int i=0;i<accounts.size();++i){
            vec.push_back(-1);
        }
        
        unordered_map<string,vector<int>> myMap;
        for(int i=0;i<accounts.size();++i){
            for(int j=1;j<accounts[i].size();++j){
                myMap[accounts[i][j]].push_back(i);
            }
        }
        
        for(auto itr=myMap.begin();itr!=myMap.end();++itr){
            for(int i=1;i<(itr->second).size();++i){
                int a=find(vec,(itr->second)[0]);
                int b=find(vec,(itr->second)[i]);
                if(a==b){
                    continue;
                }
                Union(vec,accounts, a,b);
            }
        }
        
        vector<vector<string>> result;
        for(int i=0;i<vec.size();++i){
            if(vec[i]<0){
                if(accounts[i].size()>2){
                    sort(accounts[i].begin()+1,accounts[i].end());
                    vector<string> vs;
                    vs.push_back(accounts[i][0]);
                    string last=accounts[i][0];
                    for(int j=1;j<accounts[i].size();++j){
                        if(accounts[i][j]==last){
                            continue;
                        }else{
                            vs.push_back(accounts[i][j]);
                            last=accounts[i][j];
                        }
                    }
                    accounts[i]=vs;
                }
                result.push_back(accounts[i]);
            }
        }
        
        return result;
    }
    
    int find(vector<int>& vec, int index){
        if(vec[index]<0){
            return index;
        }else{
            return vec[index]=find(vec,vec[index]);
        }
    }
    
    void Union(vector<int>& vec, vector<vector<string>>& accounts, int indexa, int indexb){
        if(vec[indexa]<vec[indexb]){
            vec[indexa]+=vec[indexb];
            vec[indexb]=indexa;
            vector<string> tmp;
            for(int i=1;i<accounts[indexb].size();++i){
                bool flag=true;
                for(int j=1;j<accounts[indexa].size();++j){
                    if(accounts[indexb][i]==accounts[indexa][j]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    tmp.push_back(accounts[indexb][i]);
                }
            }
            for(int i=0;i<tmp.size();++i){
                accounts[indexa].push_back(tmp[i]);
            }
        }else{
            vec[indexb]+=vec[indexa];
            vec[indexa]=indexb;
            vector<string> tmp;
            for(int i=1;i<accounts[indexa].size();++i){
                bool flag=true;
                for(int j=1;j<accounts[indexb].size();++j){
                    if(accounts[indexa][i]==accounts[indexb][j]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    tmp.push_back(accounts[indexa][i]);
                }
            }
            for(int i=0;i<tmp.size();++i){
                accounts[indexb].push_back(tmp[i]);
            }
        }
    }
};
