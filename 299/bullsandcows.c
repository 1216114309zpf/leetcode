class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        unordered_map<char,int> mymap;
        for(int i=0;i<secret.size();++i){
            if(mymap.count(secret[i])==0){
                mymap[secret[i]]=1;
            }else{
                ++mymap[secret[i]];
            }
        }
        
        for(int i=0;i<guess.size();++i){
            if(guess[i]==secret[i]){
                ++bulls;
                if(mymap[secret[i]]==0){
                    --cows;
                }else{
                    --mymap[secret[i]];
                }
            }else{
                if(mymap.count(guess[i])!=0 and mymap[guess[i]]!=0){
                    --mymap[guess[i]];
                    ++cows;
                }
            }
        }
        
        string result=getResult(bulls,cows);
        return result;
    }
    
    string getResult(int bulls,int cows){
        string a=toString(bulls);
        string b=toString(cows);
        string result="";
        result+=a;
        result.push_back('A');
        result+=b;
        result.push_back('B');
        return result;
    }
    
    string toString(int count){
        if(count==0)
            return "0";
        string result="";
        while(count){
            result.push_back('0'+count%10);
            count/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
