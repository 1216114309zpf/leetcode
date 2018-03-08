class MapSum {
public:
    struct Node{
        bool end;
        int sum;
        int val;
        Node* next[26];
        Node(){
            end=false;
            sum=0;
            val=0;
            for(int i=0;i<26;++i){
                next[i]=NULL;
            }
        }
    };
    Node*root;
    /** Initialize your data structure here. */
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        Node*ptr=root;
        int origin;
        for(int i=0;i<key.size();++i){
            ptr->sum+=val;
            if(!ptr->next[key[i]-'a']){
                ptr->next[key[i]-'a']=new Node();
            }
            ptr=ptr->next[key[i]-'a'];
        }
        if(ptr->end){
            origin=ptr->val;
            ptr->sum+=val;
            ptr->val=val;
            ptr=root;
            for(int j=0;j<key.size();++j){
                ptr->sum-=origin;
                ptr=ptr->next[key[j]-'a'];
            }
            ptr->sum-=origin;
            return;
        }
        ptr->end=true;
        ptr->sum+=val;
        ptr->val=val;
    }
    
    int sum(string prefix) {
        Node*ptr=root;
        for(int i=0;i<prefix.size();++i){
            if(!ptr->next[prefix[i]-'a']){
                return 0;
            }
            ptr=ptr->next[prefix[i]-'a'];
        }
        return ptr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
