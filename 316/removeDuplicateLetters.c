class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        bool* appear=new bool[26];
        for(int i=0;i<26;++i){
            appear[i]=false;
        }
        vector<vector<int>> vec;
        vector<int> tmp;
        for(int i=0;i<26;++i){
            vec.push_back(tmp);
        }
        for(int i=0;i<s.size();++i){
            if(!appear[s[i]-'a'])
                result.push_back('.');
            appear[s[i]-'a']=true;
            vec[s[i]-'a'].push_back(i);
        }
        
        for(int i=0;i<result.size();++i){
            for(int j=0;j<26;++j){
                if(!appear[j])
                    continue;
                int position=vec[j][0];
                bool flag=false;
                for(int k=j+1;k<26;++k){
                    if(appear[k] and vec[k][vec[k].size()-1]<position){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    result[i]='a'+j;
                    appear[j]=false;
                    for(int p=0;p<26;++p){
                        if(!appear[p])
                            continue;
                        while(!vec[p].empty() and vec[p][0]<position)
                            vec[p].erase(vec[p].begin());
                    }
                    break;
                }
            }
        }
        return result;
    }
};
