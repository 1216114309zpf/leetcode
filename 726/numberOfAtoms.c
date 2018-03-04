class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>> stk;
        map<string,int> myMap;
        for(int i=0;i<formula.size();++i){
            if(formula[i]>='A' and formula[i]<='Z'){
                string name="";
                name.push_back(formula[i]);
                ++i;
                while(i<formula.size() and formula[i]>='a' and formula[i]<='z'){
                    name.push_back(formula[i]);
                    ++i;
                }
                string count="";
                while(i<formula.size() and formula[i]>='0' and formula[i]<='9'){
                    count.push_back(formula[i]);
                    ++i;
                }
                --i;
                pair<string,int> item;
                item.first=name;
                item.second=atoi(count);
                stk.push(item);
            }else if(formula[i]=='('){
                string name="(";
                int count=-1;
                pair<string,int> item;
                item.first=name;
                item.second=count;
                stk.push(item);
            }else{
                string count="";
                ++i;
                while(i<formula.size() and formula[i]>='0' and formula[i]<='9'){
                    count.push_back(formula[i]);
                    ++i;
                }
                --i;
                
                if(count==""){
                    continue;
                }
                int cnt=atoi(count);

                stack<pair<string,int>> tmp;
                while(stk.top().first!="("){
                    pair<string,int> item=stk.top();
                    item.second*=cnt;
                    stk.pop();
                    tmp.push(item);
                }
                stk.pop();
                while(!tmp.empty()){
                    stk.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        
        while(!stk.empty()){
            pair<string,int> item=stk.top();
            if(myMap.count(item.first)==0){
                myMap[item.first]=item.second;
            }else{
                myMap[item.first]+=item.second;
            }
            stk.pop();
        }
        
        string result;
        for(auto itr=myMap.begin();itr!=myMap.end();++itr){
            //cout<<itr->first<<" "<<myMap[itr->first]<<endl;
            result+=((*itr).first);
            if(itr->second!=1)
                result+=(itoa((*itr).second));
        }
        return result;
    }
    
    int atoi(string str){
        if(str=="")
            return 1;
        int result=0;
        for(int i=0;i<str.size();++i){
            result*=10;
            result+=(str[i]-'0');
        }
        return result;
    }
    
    string itoa(int count){
        string result="";
        while(count){
            result.push_back('0'+count%10);
            count/=10;
        }
        reverse(result.begin(),result.end());
        return r
