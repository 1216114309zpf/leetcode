class WordDictionary {
public:
    struct Node{
        bool end;
        Node*next[26];
        Node(){
            end=false;
            for(int i=0;i<26;++i){
                next[i]=NULL;
            }
        }
    };
    Node* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node*ptr=root;
        for(int i=0;i<word.size();++i){
            if(!ptr->next[word[i]-'a']){
                ptr->next[word[i]-'a']=new Node();
            }
            ptr=ptr->next[word[i]-'a'];
        }
        ptr->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node*ptr=root;
        for(int i=0;i<word.size();++i){
            if(word[i]=='.'){
                
                string tmp="";
                for(int p=i+1;p<word.size();++p)
                    tmp.push_back(word[p]);
                
                for(int j=0;j<26;++j){
                    if(!ptr->next[j]){
                        continue;
                    }
                    Node* node=root;
                    root=ptr->next[j];
                    if(search(tmp)){
                        root=node;
                        return true;
                    }
                    root=node;
                }
                return false;
            }else{
                if(!ptr->next[word[i]-'a']){
                    return false;
                }
                ptr=ptr->next[word[i]-'a'];
            }
        }
        return ptr->end;
    }
    
};

