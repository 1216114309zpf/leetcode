class Solution {
public:
    int nextGreaterElement(int n) {
        string number=int2string(n);
        stack<char> stk;
        for(int i=number.size()-1;i>=0;--i){
            if(stk.empty() or number[i]>=stk.top()){
                stk.push(number[i]);
            }else{
                int replace=i;
                while(!stk.empty() and stk.top()>number[i]){
                    ++replace;
                    if(stk.top()==number[i]+1)
                        break;
                    stk.pop();
                }
                char tmp=number[i];
                number[i]=number[replace];
                number[replace]=tmp;
                sort(number.begin()+1+i,number.end());
                long long int result=string2int(number);
                if(result>0x7fffffff)
                    return -1;
                else
                    return result;
            }
        }
        return -1;
    }
    string int2string(int n){
        string result;
        while(n){
            result.push_back('0'+n%10);
            n/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    long long int string2int(string n){
        long long int result=0;
        for(int i=0;i<n.size();++i){
            result*=10;
            result+=(n[i]-'0');
        }
        return result;
    }
};
