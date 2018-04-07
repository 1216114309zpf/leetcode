class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string current=getString(board);
        string target="123450";
        int length=0;
        unordered_map<string,bool> mymap;
        queue<string> que;
        que.push(current);
        que.push("");
        mymap[current]=true;
        while(!que.empty()){
            string ptr=que.front();
            que.pop();
            if(ptr==""){
                if(que.empty()){
                    return -1;
                }else{
                    ++length;
                    que.push("");
                }
            }else{
                if(ptr==target){
                    return length;
                }
                vector<string> ajacents=getAjacent(ptr);
                for(int i=0;i<ajacents.size();++i){
                    if(mymap.count(ajacents[i])==0){
                        que.push(ajacents[i]);
                        mymap[ajacents[i]]=true;
                    }
                }
            }
        }
        return -1;
    }
    
    string getString(vector<vector<int>>&board){
        string result="";
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                result.push_back('0'+board[i][j]);
            }
        }
        return result;
    }
    
    vector<string> getAjacent(string str){
        vector<string> result;
        for(int i=0;i<str.size();++i){
            if(str[i]=='0'){
                switch(i){
                    case 0:
                        result.push_back(swap(str,0,1));
                        result.push_back(swap(str,0,3));
                        break;
                    case 1:
                        result.push_back(swap(str,1,0));
                        result.push_back(swap(str,1,2));
                        result.push_back(swap(str,1,4));
                        break;
                    case 2:
                        result.push_back(swap(str,2,5));
                        result.push_back(swap(str,2,1));
                        break;
                    case 3:
                        result.push_back(swap(str,3,0));
                        result.push_back(swap(str,3,4));
                        break;
                    case 4:
                        result.push_back(swap(str,4,3));
                        result.push_back(swap(str,4,1));
                        result.push_back(swap(str,4,5));
                        break;
                    case 5:
                        result.push_back(swap(str,5,4));
                        result.push_back(swap(str,5,2));
                        break;    
                }
                break;
            }
        }
        
        return result;
    }
    
    string swap(string str,int i,int j){
        char c=str[i];
        str[i]=str[j];
        str[j]=c;
        return str;
    }
};
