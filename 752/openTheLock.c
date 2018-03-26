class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> myMap;
        for(int i=0;i<deadends.size();++i){
            myMap[deadends[i]]=2; //2 for dead
        }
        
        if("0000"==target){
            return 0;
        }
        if(myMap["0000"]==2){
            return -1;
        }
        
        queue<string> que;
        que.push("0000");
        que.push("");
        myMap["0000"]=1; //1 for checked or in queue;
        int steps=0;
        
        while(!que.empty()){
            string str=que.front();
            que.pop();
            if(str==""){
                if(!que.empty()){
                    ++steps;
                    que.push("");
                }
            }else{
                if(str==target){
                    return steps;
                }else{
                    vector<string> vec=getVariants(str);
                    for(int i=0;i<vec.size();++i){
                        if(myMap.count(vec[i])==0){
                            que.push(vec[i]);
                            myMap[vec[i]]=1;
                        }else{
                            continue; 
                        }
                    }
                }
            }
        }
        
        return -1;
    }
    
    vector<string> getVariants(string str){
        vector<string> result;
        for(int i=0;i<4;++i){
            string tmp=str;
            string another=str;
            if(str[i]=='0'){
                tmp[i]='1';
                another[i]='9';
            }else if(str[i]=='9'){
                tmp[i]='8';
                another[i]='0';
            }else{
                tmp[i]-=1;
                another[i]+=1;
            }
            result.push_back(tmp);
            result.push_back(another);
        }
        return result;
    }
};
