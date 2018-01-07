class Solution {
public:
    string multiply(string num1, string num2) {
        string result="";
        for(int i=0;i<num2.size();++i){
            result.push_back('0');
            result=add(result,multi(num1,num2[i]-'0'));
        }
        while(result[0]=='0' and result.size()!=1)
            result.erase(result.begin());
        return result;
    }
    
    string multi(string num, int c){
        string result;
        int carry=0;
        for(int i=num.size()-1;i>=0;--i){
            int tmp=(num[i]-'0')*c+carry;
            result.push_back(tmp%10+'0');
            carry=tmp/10;
        }
        if(carry>0)
            result.push_back(carry+'0');
        reverse(result.begin(),result.end());
        return result;
    }
    string add(string num1, string num2){
        if(num1.size()==0)
            return num2;
        if(num2.size()==0)
            return num1;
        string result;
        int first=num1.size()-1;
        int second=num2.size()-1;
        int carry=0;
        while(first>=0 and second>=0){
            int tmp=carry+(num1[first]-'0')+(num2[second]-'0');
            if(tmp>9){
                carry=1;
                result.push_back(tmp-10+'0');
            }else{
                carry=0;
                result.push_back(tmp+'0');
            }
            --first;
            --second;
        }
        
        string left="";
        int position;
        if(first>=0){
            left=num1;
            position=first;
        }else if(second>=0){
            left=num2;
            position=second;
        }else{
            if(carry==1)
                result.push_back('1');
        }
        
        if(left!=""){
            while(carry==1){
                if(position<0){
                    result.push_back('1');
                    break;
                }
                int tmp=carry+left[position]-'0';
                if(tmp>9){
                    carry=1;
                    result.push_back('0'+tmp-10);
                }else{
                    carry=0;
                    result.push_back(tmp+'0');
                }
                --position;
            }
            
            while(position>=0){
                result.push_back(left[position]);
                --position;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
