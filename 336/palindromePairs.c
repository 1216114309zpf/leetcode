class Solution {
public:
    struct TrieNode{
        TrieNode *next[26];
        vector<int> candidate;
        int index;
        
        TrieNode():index(-1){};
    };
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root;
        root=new TrieNode();
        for(int i=0;i<26;++i){
            root->next[i]=NULL;
        }
        
        for(int i=0;i<words.size();++i){
            addWords(root,words[i],i);
        }
        
        vector<vector<int>> result;
        for(int i=0;i<words.size();++i){
            search(root,words[i],i,result);
        }
        return result;
    }
    
    void addWords(TrieNode* root,string word,int index){
        for(int i=word.size()-1;i>=0;--i){
            if(isPalindrome(word,0,i)){
                root->candidate.push_back(index);
            }
            
            if(root->next[word[i]-'a']){
                
            }else{
                root->next[word[i]-'a']=new TrieNode();
                TrieNode* tmp=root->next[word[i]-'a'];
                for(int i=0;i<26;++i)
                    tmp->next[i]=NULL;
            }
            
            root=root->next[word[i]-'a'];
        }
        root->candidate.push_back(index);
        root->index=index;
    }
    
    void search(TrieNode* root,string word, int index, vector<vector<int>> &result){
        for(int i=0;i<word.size();++i){
            if(root->index>=0 and root->index!=index and isPalindrome(word,i,word.size()-1)){
                vector<int> tmp;
                tmp.push_back(index);
                tmp.push_back(root->index);
                result.push_back(tmp);
            }
            
            root=root->next[word[i]-'a'];
            
            if(!root){
                return;
            }
        }
        for(int i=0;i<root->candidate.size();++i){
            if(index!=root->candidate[i]){
                vector<int> tmp;
                tmp.push_back(index);
                tmp.push_back(root->candidate[i]);
                result.push_back(tmp);
            }
        }
    }
    
    bool isPalindrome(string word, int start, int end){
        while(end>start){
            if(word[end]!=word[start]){
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
