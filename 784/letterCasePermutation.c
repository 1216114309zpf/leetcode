class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string current=S;
        recursive(result, current, 0);
        return result;
    }
    
    void recursive(vector<string>& result, string current, int index){
        while(index<current.size() and current[index]>='0' and current[index]<='9'){
            ++index;
        }
        
        if(index==current.size()){
            result.push_back(current);
            return;
        }
        
        recursive(result,current, index+1);
        
        if(current[index]>='a'){
            current[index]-=('a'-'A');
        }else{
            current[index]+=('a'-'A');
        }
        
        recursive(result,current,index+1);
    }
};
