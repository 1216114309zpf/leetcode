class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
        vector<string> result;
        unsigned int number = str2uint(ip);
        while(range){
            unsigned int candidate = 0x00000001;
            int itr=1;
            while(candidate <= range){
                if(candidate & number or candidate*2>range){
                    range-=candidate;
                    result.push_back(toString(number,33-itr));
                    number+=candidate;
                    break;
                }
                candidate<<=1;
                ++itr;
            }
        }
        return result;
    }
    
    unsigned int str2uint(string ip){
        unsigned int result=0;
        int current = 0;
        vector<int> inter;
        for(int i=0; i<4; ++i){
            int tmp=0;
            while(current<ip.size() and ip[current]!='.'){
                tmp*=10;
                tmp+=(ip[current]-'0');
                ++current;
            }
            inter.push_back(tmp);
            ++current;
        }
        for(int i=0;i<4;++i){
            result*=256;
            result+=inter[i];
        }
        return result;
    }
    
    string toString(unsigned int number, int mask){
        string result="";
        unsigned int refer = 0xff000000;
        int itr=0;
        while(itr<4){
            unsigned int current = number&refer;
            current>>=24;
            number<<=8;
            result+=int2str(current);
            if(itr!=3)
                result.push_back('.');
            ++itr;
        }
        result.push_back('/');
        result=result+int2str(mask);
        return result;
    }
    
    string int2str(unsigned int number){
        string result="";
        if(number<10){
            result.push_back('0'+number);
            return result;
        }
        result=int2str(number/10);
        result.push_back('0'+number%10);
        return result;
    }
};
