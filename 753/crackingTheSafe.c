class Solution {
public:
    string crackSafe(int n, int k) {
        string result="";
        string last="";
        for(int i=0;i<n;++i){
            last.push_back('0');
            result.push_back('0');
        }
        
        unordered_map<string,int> myMap;
        
        stack<string> stk;
        stk.push(last);
        
        while(!stk.empty()){
            string current=stk.top();
            stk.pop();
            if(myMap.count(current)!=0){
                continue;
            }else{
                myMap[current]=1;//1 for accessed;
            }
            result+=additional(last,current);
            last=current;
            current.erase(current.begin());
            for(int i=0;i<k;++i){
                string tmp=current;
                tmp.push_back('0'+i);
                if(myMap.count(tmp)==0){
                    //myMap[tmp]=1;
                    stk.push(tmp);
                }
            }
        }
        return result;
    }
    
    string additional(string a,string b){
        string result="";
        if(a==b){
            return "";
        }
        string tmpa=a,tmpb=b;
        while(tmpa!=tmpb){
            tmpa.erase(tmpa.begin());
            result.push_back(tmpb[tmpb.size()-1]);
            tmpb.pop_back();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
