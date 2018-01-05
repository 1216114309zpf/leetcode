class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        int hIndex=0;
        while(hIndex<haystack.size()){
            int nIndex=0;
            while(nIndex<needle.size()){
                while(hIndex<haystack.size() and needle[nIndex]!=haystack[hIndex])
                    ++hIndex;
                if(hIndex==haystack.size())
                    return -1;
                ++nIndex;
                ++hIndex;
            }
            if(isStrStr(haystack,needle,hIndex))
                return hIndex-needle.size();
            else
                hIndex-=needle.size();
        }
        return -1;
    }
    
    bool isStrStr(string haystack,string needle, int index){
        for(int i=0;i<needle.size();++i){
            if(haystack[index-needle.size()+i]!=needle[i])
                return false;
        }
        return true;
    }
};
