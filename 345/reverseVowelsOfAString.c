class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right and !isVowel(s[left]))
                ++left;
            if(left==right)
                return s;
            
            while(right>left and !isVowel(s[right]))
                --right;
            if(left==right)
                return s;
            
            char c=s[left];
            s[left]=s[right];
            s[right]=c;
            
            ++left;
            --right;
        }
        return s;
    }
    
    bool isVowel(char c){
        if(c=='a' or c=='A')
            return true;
        if(c=='e' or c=='E')
            return true;
        if(c=='i' or c=='I')
            return true;
        if(c=='o' or c=='O')
            return true;
        if(c=='u' or c=='U')
            return true;
        return false;
    }
};
