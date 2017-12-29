class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int first=0;
        for(int left=1;left<=3;++left){
            if(left>=s.size())
                break;
            if(left!=1 and s[0]=='0')
                break;
            first*=10;
            first+=s[left-1]-'0';
            if(first>255)
                break;
            
            int second=0;
            for(int mid=left+1;mid<=left+3;++mid){
                if(mid>=s.size())
                    break;
                if(mid!=left+1 and s[left]=='0')
                    break;
                second*=10;
                second+=s[mid-1]-'0';
                if(second>255)
                    break;
                
                int third=0;
                for(int right=mid+1;right<=mid+3;++right){
                    if(right>=s.size())
                        break;
                    if(right!=mid+1 and s[mid]=='0')
                        break;
                    
                    third*=10;
                    third+=s[right-1]-'0';
                    if(third>255)
                        break;
                    
                    int forth=0;
                    if(s.size()-right>3)
                        continue;
                    bool flag=false;
                    for(int remain=right+1;remain<=s.size();++remain){
                        if(remain!=right+1 and s[right]=='0'){
                            flag=true;
                            break;
                        }
                        forth*=10;
                        forth+=s[remain-1]-'0';
                    }
                    
                    if(!flag and forth<=255){
                        string current;
                        current+=toString(first);
                        current.push_back('.');
                        current+=toString(second);
                        current.push_back('.');
                        current+=toString(third);
                        current.push_back('.');
                        current+=toString(forth);
                        result.push_back(current);
                    }
                }
            }
        }
        return result;
    }
    
    string toString(int number){
        string result;
        if(number<10){
            result.push_back('0'+number);
            return result;
        }
        return toString(number/10)+toString(number%10);
    }
};
