class Solution {
public:
    string longestPalindrome(string s) {
        string result="";
        string str="#";
        for(int i=0;i<s.size();++i){
            str.push_back(s[i]);
            str.push_back('#');
        }

        for(int i=0;i<str.size();i++){
            string tmp=getLongest(str,i);
            if(tmp.size()>result.size()){
                result=tmp;
            }
        }
        
        string tmp=result;
        result="";
        for(int i=0;i<tmp.size();++i){
            if(tmp[i]!='#'){
                result.push_back(tmp[i]);
            }
        }
        return result;
    }
    
    string getLongest(string str,int index){
        int left=index;
        int right=index;
        while(left!=0 and right!=str.size()-1 and str[left]==str[right]){
            --left;
            ++right;
        }
        //cout<<left<<" "<<right<<endl;
        if(str[left]!=str[right]){
            left++;
            right--;
        }
        
        string s="";
        for(int i=left;i<=right;++i){
            s.push_back(str[i]);
        }
        
        return s;
    }
};
