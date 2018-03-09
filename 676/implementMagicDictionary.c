class MagicDictionary {
public:
    struct Node{
        bool end;
        Node* next[26];
        Node(){
            end=false;
            for(int i=0;i<26;++i){
                next[i]=NULL;
            }
        }
    };
    Node*root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root=new Node();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();++i){
            Node*ptr=root;
            for(int j=0;j<dict[i].size();++j){
                if(!ptr->next[dict[i][j]-'a']){
                    ptr->next[dict[i][j]-'a']=new Node();
                }
                ptr=ptr->next[dict[i][j]-'a'];
            }
            ptr->end=true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        Node*ptr=root;
        for(int i=0;i<word.size();++i){
            int index=-1;
            for(int j=0;j<26;++j){
                if(!ptr->next[j]){
                    continue;
                }else if(j!=word[i]-'a'){
                    string str="";
                    for(int p=i+1;p!=word.size();++p){
                        str.push_back(word[p]);
                    }
                    if(exactSearch(ptr->next[j],str)){
                        return true;
                    }
                }else{
                    index=j;
                }
                
            }
            if(index!=-1){
                ptr=ptr->next[index];
            }else{
                return false;
            }
        }
        return false;
    }
    
    bool exactSearch(Node* root,string word){
        for(int i=0;i<word.size();++i){
            if(!root->next[word[i]-'a']){
                return false;
            }
            root=root->next[word[i]-'a'];
        }
        return root->end;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
