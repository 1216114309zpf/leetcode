class Solution {
public:
    int findIntegers(int num) {
        string str=toString(num);
        vector<int> array(str.size()+1,1);
        array[1]=2;
        for(int i=2;i<str.size()+1;++i){
            array[i]=array[i-1]+array[i-2];
        }
        
        int result=help(array,str,0);
        return result;
    }
    
    int help(vector<int>&array,string str,int index){
         if(index==str.size()-1){
             return array[1];
         }
        int result=array[str.size()-index-1];
        
        if(index+1<str.size() and str[index+1]=='1'){
            return result+=array[str.size()-index-2];
        }
        
        index+=2;
        
        while(index<str.size() and str[index]=='0'){
            ++index;
        }
        
        if(index>=str.size()){
            return result+1;
        }else{
            return result+help(array,str,index);
        }
    }
    
    string toString(int num){
        string result="";
        while(num){
            result.push_back('0'+num%2);
            num/=2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
