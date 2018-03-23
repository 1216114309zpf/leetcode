class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return help(price,special,needs,0);
    }
    
    int help(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int current){
        int result=0;
        for(int i=0;i<price.size();++i){
            result+=price[i]*needs[i];
        }
        
        if(current==special.size()){
            return result;
        }
        
        int money;
        int now=0;
        
        int notBuy=help(price,special,needs,current+1);
        if(notBuy<result){
            result=notBuy;
        }
        
        while(getTotal(price, special[current],money) and canBuy(special[current],needs)){
            int tmp=now+money+help(price,special,needs,current+1);
            now+=money;
            if(result>tmp){
                result=tmp;
            }
        }
        return result;
    }
    
    bool canBuy(vector<int> bag, vector<int>& needs){
        for(int i=0;i<needs.size();++i){
            needs[i]-=bag[i];
            if(needs[i]<0)
                return false;
        }
        return true;
    }
    
    bool getTotal(vector<int> price, vector<int> bag, int &money){
        int result=0;
        for(int i=0;i<price.size();++i){
            result+=price[i]*bag[i];
        }
        
        if(result<bag[bag.size()-1]){
            return false;
        }else{
            money=bag[bag.size()-1];
            return true;
        }
    }
};
