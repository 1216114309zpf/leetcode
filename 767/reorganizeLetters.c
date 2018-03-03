class Solution {
    struct Node{
        char c;
        int count;
    };
public:
    string reorganizeString(string S) {
        vector<Node> array;
        for(int i=0;i<26;++i){
            Node node;
            node.count=0;
            node.c=i+'a';
            array.push_back(node);
        }
        
        for(int i=0;i<S.size();++i){
            ++(array[S[i]-'a'].count);
        }
        
        sort(array.begin(),array.end(),compare);
        
        vector<string> vec;
        for(int i=0;i<array[0].count;++i){
            string str;
            str.push_back(array[0].c);
            vec.push_back(str);
        }
        
        int current=0;
        for(int i=1;i<26;++i){
            if(array[i].count==0){
                break;
            }else if(array[i].count==array[0].count){
                for(int j=0;j<vec.size();++j){
                    vec[j].push_back(array[i].c);
                }
            }else{
                for(int j=0;j<array[i].count;++j){
                    vec[current].push_back(array[i].c);
                    ++current;
                    if(current==vec.size()-1){
                        current=0;
                    }
                }
            }
        }
        
        string result="";
        for(int i=0;i<vec.size();++i){
            result+=vec[i];
        }
        for(int i=0;i<result.size()-1;++i){
            if(result[i]==result[i+1]){
                return "";
            }
        }
        return result;
    }
    
    static bool compare(Node &a,Node &b){
        return a.count>b.count;
    }
};
