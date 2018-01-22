class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        int *array=new int[26];
        bool *flag=new bool[26];
        for(int i=0;i<26;++i){
            array[i]=0;
            flag[i]=false;
        }
        for(int i=0;i<S.size();++i){
            ++array[S[i]-'a'];
        }
        int itr=0;
        int count=0;
        flag[S[0]-'a']=true;
        while(itr<S.size()){
            if(!finished(flag)){
                --array[S[itr]-'a'];
                if(array[S[itr]-'a']!=0){
                    flag[S[itr]-'a']=true;
                }else{
                    flag[S[itr]-'a']=false;
                }
                ++count;
                ++itr;
            }else{
                result.push_back(count);
                count=0;
                flag[S[itr]-'a']=true;
            }
        }
        result.push_back(count);
        return result;
    }
    
    bool finished(bool flag[]){
        for(int i=0;i<26;++i){
            if(flag[i])
                return false;
        }
        return true;
    }
};
