class Trie {
    
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
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* ptr=root;
        for(int i=0;i<word.size();++i){
            if(!ptr->next[word[i]-'a']){
                ptr->next[word[i]-'a']=new Node();
            }
            ptr=ptr->next[word[i]-'a'];
        }
        ptr->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node*ptr=root;
        for(int i=0;i<word.size();++i){
            if(!ptr->next[word[i]-'a']){
                return false;
            }
            ptr=ptr->next[word[i]-'a'];
        }
        return ptr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node*ptr=root;
        for(int i=0;i<prefix.size();++i){
            if(!ptr->next[prefix[i]-'a']){
                return false;
            }
            ptr=ptr->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
