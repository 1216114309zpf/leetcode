class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        stable_sort(words.begin(),words.end(), compare);
        
        vector<int> vec;
        for(int i=0;i<26;++i)
            vec.push_back(0);
        
        for(int i=0; i<licensePlate.size();++i){
            if(licensePlate[i]>='a' and licensePlate[i]<='z')
                ++vec[licensePlate[i]-'a'];
            if(licensePlate[i]>='A' and licensePlate[i]<='Z')
                ++vec[licensePlate[i]-'A'];
        }
        
        for(int i=0; i<words.size(); ++i){
            vector<int> tmpvec = vec;
            for(int j=0; j<words[i].size(); ++j){
                if(tmpvec[words[i][j]-'a'])
                    --tmpvec[words[i][j]-'a'];
            }
                             
            bool flag = true;
            for(int i=0; i<26; ++i){
                if(tmpvec[i]!=0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return words[i];
        }
    }
    
    static bool compare(string a, string b){
        return a.size() < b.size();
    }
};
