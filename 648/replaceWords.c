class Solution {
public:
    struct Node{
        bool end;
        Node* next[26];
        Node(){
            end=false;
            for(int i=0;i<26;++i)
                next[i]=NULL;
        }
    };
    string replaceWords(vector<string>& dict, string sentence) {
        Node* root=new Node();
        for(int i=0;i<dict.size();++i){
            Node*ptr=root;
            for(int j=0;j<dict[i].size();++j){
                if(ptr->next[dict[i][j]-'a']==NULL){
                    ptr->next[dict[i][j]-'a']=new Node();
                }
                ptr=ptr->next[dict[i][j]-'a'];
            }
            ptr->end=true;
        }
        
        vector<string> words=parse(sentence);
        string result="";
        for(int i=0;i<words.size();++i){
            string tmp="";
            Node*ptr=root;
            int j;
            for(j=0;j<words[i].size();++j){
                if(ptr->end){
                    result+=tmp;
                    break;
                }else if(ptr->next[words[i][j]-'a']){
                    tmp.push_back(words[i][j]);
                    ptr=ptr->next[words[i][j]-'a'];
                }else{
                    result+=words[i];
                    break;
                }
            }
            
            if(j==words[i].size()){
                result+=words[i];
            }
            if(i!=words.size()-1){
                result.push_back(' ');
            }
        }
        return result;
    }
    
    vector<string> parse(string str){
        vector<string> result;
        str.push_back(' ');
        for(int i=0;i<str.size();++i){
            string tmp="";
            if(str[i]==' '){
                continue;
            }else{
                while(str[i]!=' '){
                    tmp.push_back(str[i]);
                    ++i;
                }
                result.push_back(tmp);
            }
        }
        return result;
    }
};
