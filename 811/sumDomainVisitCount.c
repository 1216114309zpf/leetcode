class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mymap;
        for(int i=0;i<cpdomains.size();++i){
            parsecp(cpdomains[i],mymap);
        }
        vector<string> result;
        for(auto itr=mymap.begin();itr!=mymap.end();++itr){
            string tmp=combine(itr->first,itr->second);
            result.push_back(tmp);
        }
        return result;
    }
    
    void parsecp(string cp,unordered_map<string,int>&mymap){
        string str="";
        int count=0;
        vector<string> vs;
        for(int i=cp.size()-1;i>=0;--i){
            while(i>=0 and cp[i]!='.' and cp[i]!=' '){
                str.push_back(cp[i]);
                --i;
            }
            string tmp=str;
            reverse(tmp.begin(),tmp.end());
            vs.push_back(tmp);
            
            if(cp[i]=='.'){
                str.push_back(cp[i]);
            }else{
                str="";
                for(int j=0;j<i;++j){
                    str.push_back(cp[j]);
                }
                count=toInt(str);
                break;
            }
        }
        for(int i=0;i<vs.size();++i){
            if(mymap.count(vs[i])==0){
                 mymap[vs[i]]=count;
            }else{
                 mymap[vs[i]]+=count;
            }
        }
    }
    
    int toInt(string str){
        int result=0;
        for(int i=0;i<str.size();++i){
            result*=10;
            result+=(str[i]-'0');
        }
        return result;
    }
    
    string combine(string str,int count){
        string result="";
        string cnt=toString(count);
        result+=cnt;
        result+=" ";
        result+=str;
        return result;
    }
    
    string toString(int count){
        string str="";
        while(count){
            str.push_back('0'+count%10);
            count/=10;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
