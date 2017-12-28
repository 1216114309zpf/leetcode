class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar=0;
        int av=0;
        int br=0;
        int bv=0;
        
        getNumber(a,ar,av);
        getNumber(b,br,bv);
        
        int real = ar*br - av*bv;
        int virt = ar*bv + av*br;
        
        string result;
        if(real<0){
            result.push_back('-');
            real=-real;
        }
        
        result+=toString(real);
        result.push_back('+');
        if(virt<0){
            result.push_back('-');
            virt=-virt;
        }else{
            //result.push_back('+');
        }
        result+=toString(virt);
        result.push_back('i');
        return result;
    }
    
    void getNumber(string str, int &real, int &virt){
        int itr=0;
        int rs,vs;
        real=0;
        virt=0;
        if(str[itr]=='-'){
            ++itr;
            rs=-1;
        }else{
            rs=1;
        }
        
        while(itr<str.size() and str[itr]!='+'){
            real*=10;
            real+=(str[itr]-'0');
            ++itr;
        }
        
        ++itr;
        if(str[itr]=='-'){
            vs=-1;
            ++itr;
        }else{
            vs=1;
        }
        
        while(itr<str.size() and str[itr]!='i'){
            virt*=10;
            virt+=(str[itr]-'0');
            ++itr;
        }
        
        real*=rs;
        virt*=vs;
    }
    string toString(int number){
        string result;
        if(number<10){
            result.push_back(number+'0');
            return result;
        }
        result=toString(number/10)+toString(number%10);
        return result;
    }
};
