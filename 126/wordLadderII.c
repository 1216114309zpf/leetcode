class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> hasChecked;
        unordered_map<string,vector<string>> neighbors;
        for(int i=0;i<wordList.size();++i){
            for(int j=0;j<i;++j){
                if(isNeighbor(wordList[i],wordList[j])){
                    neighbors[wordList[i]].push_back(wordList[j]);
                    neighbors[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if(neighbors.count(beginWord)==0){
            for(int i=0;i<wordList.size();++i){
                if(isNeighbor(beginWord,wordList[i])){
                    neighbors[beginWord].push_back(wordList[i]);
                }
            }
        }
        vector<vector<string>> result;
        queue<vector<string>> que;
        vector<string> vec,empty;
        vec.push_back(beginWord);
        que.push(vec);
        que.push(empty);
        hasChecked[beginWord]=true;
        
        bool find=false;
        vector<string> toBeMarked;
        while(!que.empty()){
            vector<string> ptr=que.front();
            que.pop();
            if(ptr.size()==0){
                if(que.empty()){
                    return result;
                }else{
                    if(find){
                        return result;
                    }else{
                        for(int i=0;i<toBeMarked.size();++i){
                            hasChecked[toBeMarked[i]]=true;
                        }
                        toBeMarked.clear();
                        que.push(empty);
                    }
                }
            }else{
                for(int i=0;i<neighbors[ptr[ptr.size()-1]].size();++i){
                    if(hasChecked.count(neighbors[ptr[ptr.size()-1]][i])==0){
                        if(neighbors[ptr[ptr.size()-1]][i]==endWord){
                            vector<string> tmp=ptr;
                            tmp.push_back(endWord);
                            result.push_back(tmp);
                            find=true;
                            break;
                        }else{
                            vector<string> tmp=ptr;
                            bool flag=false;
                            for(int j=0;j<tmp.size();++j){
                                if(tmp[j]==neighbors[ptr[ptr.size()-1]][i]){
                                    flag=true;
                                    break;
                                }
                            }
                            if(flag)
                                continue;
                            tmp.push_back(neighbors[ptr[ptr.size()-1]][i]);
                            que.push(tmp);
                            //hasChecked[neighbors[ptr[ptr.size()-1]][i]]=true;
                            toBeMarked.push_back(neighbors[ptr[ptr.size()-1]][i]);
                        }
                    }
                }
            }
        }
        return result;
    }
    
    bool isNeighbor(string a,string b){
        if(a.size()<b.size()){
            return false;
        }
        
        int count=0;
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]){
                ++count;
            }
        }
        return count==1;
    }
};
