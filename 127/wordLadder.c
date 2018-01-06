class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool *checked = new bool[wordList.size()];
        for(int i=0;i<wordList.size();++i){
            checked[i]=false;
        }
        
        queue<string> que;
        que.push(beginWord);
        que.push("");
        int level=1;
        while(!que.empty()){
            string current=que.front();
            que.pop();
            if(current==""){
                ++level;
                if(!que.empty())
                    que.push("");
                continue;
            }
            for(int i=0;i<wordList.size();++i){
                if(!checked[i] and adjacent(current,wordList[i])){
                    if(wordList[i]==endWord)
                        return level+1;
                    checked[i]=true;
                    que.push(wordList[i]);
                }
            }
        }
        return 0;
    }
    bool adjacent(string front, string end){
        int count=0;
        for(int i=0; i<front.size(); ++i){
            if(front[i]!=end[i]){
                ++count;
                if(count>1)
                    return false;
            }
        }
        return true;
    }
};
