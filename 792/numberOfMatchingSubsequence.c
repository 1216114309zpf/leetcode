class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> count;
        for(int i=0;i<26;++i){
            count.push_back(0);
        }
        
        unordered_map<int,int> myMap;
        for(int i=0;i<S.size();++i){
            int vec=(++count[S[i]-'a']);
            vec*=100;
            vec+=S[i];
            myMap[vec]=i;
        }
        
        int result=0;
        for(int i=0;i<words.size();++i){
            int current=0;
            bool flag=true;
            for(int q=0;q<26;++q){
                count[q]=0;
            }
            for(int j=0;j<words[i].size();++j){
                ++count[words[i][j]-'a'];
                int vec=100;
                vec*=count[words[i][j]-'a'];
                vec+=(words[i][j]);
                if(myMap.count(vec)==0){
                    flag=false;
                    break;
                }else{
                    while(myMap.count(vec)!=0 and myMap[vec]<current){
                        ++count[words[i][j]-'a'];
                        vec=100;
                        vec*=count[words[i][j]-'a'];
                        vec+=(words[i][j]);
                    }
                    if(myMap.count(vec)==0){
                        flag=false;
                        break;
                    }else{
                        current=myMap[vec];
                    }
                }
            }
            if(flag){
                ++result;
            }
        }
        return result;
    }
};
