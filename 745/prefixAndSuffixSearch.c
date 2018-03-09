class WordFilter {
public:
    struct Node{
        vector<int> weights;
        Node*next[26];
        Node(){
            for(int i=0;i<26;++i){
                next[i]=NULL;
            }
        }
    };
    Node*preRoot,*sufRoot;
    WordFilter(vector<string> words) {
        preRoot=new Node();
        sufRoot=new Node();
        
        for(int i=0;i<words.size();++i){
            Node*ptr=preRoot;
            ptr->weights.push_back(i);
            for(int j=0;j<words[i].size();++j){
                if(!ptr->next[words[i][j]-'a']){
                    ptr->next[words[i][j]-'a']=new Node();
                }
                ptr=ptr->next[words[i][j]-'a'];
                ptr->weights.push_back(i);
            }
            
            reverse(words[i].begin(),words[i].end());
            ptr=sufRoot;
            ptr->weights.push_back(i);
            for(int j=0;j<words[i].size();++j){
                if(!ptr->next[words[i][j]-'a']){
                    ptr->next[words[i][j]-'a']=new Node();
                }
                ptr=ptr->next[words[i][j]-'a'];
                ptr->weights.push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(),suffix.end());
        Node*ptr=preRoot;
        vector<int> pre;
        for(int i=0;i<prefix.size();++i){
            if(!ptr->next[prefix[i]-'a']){
                return -1;
            }else{
                ptr=ptr->next[prefix[i]-'a'];
            }
        }
        pre=ptr->weights;
        
        ptr=sufRoot;
        vector<int> suf;
        for(int i=0;i<suffix.size();++i){
            if(!ptr->next[suffix[i]-'a']){
                return -1;
            }else{
                ptr=ptr->next[suffix[i]-'a'];
            }
        }
        suf=ptr->weights;
        
        int p=pre.size()-1;
        int s=suf.size()-1;
        while(p>=0 and s>=0){
            if(pre[p]==suf[s]){
                return pre[p];
            }else if(pre[p]>suf[s]){
                p--;
            }else{
                s--;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
