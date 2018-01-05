class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> countArray;
        int currentCount=0;
        char current='c';
        
        for(int i=0;i<s.size();++i){
            if(s[i]!=current){
                if(currentCount!=0)
                    countArray.push_back(currentCount);
                currentCount=1;
                current=s[i];
            }else{
                ++currentCount;
            }
        }
        countArray.push_back(currentCount);
        
        int result=0;
        for(int i=1;i<countArray.size();++i)
            result+=min(countArray[i],countArray[i-1]);
        return result;
    }
};
