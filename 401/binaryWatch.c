class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> hours={8,4,2,1};
        vector<int> minutes={32,16,8,4,2,1};
        for(int i=0;i<=min(3,num);++i){
            vector<int> hour=getpermute(hours,i,12);
            vector<int> minute=getpermute(minutes,num-i,60);
            vector<string> current=combine(hour,minute);
            for(int i=0;i<current.size();++i){
                result.push_back(current[i]);
            }
        }
        return result;
    }
    
    vector<int> getpermute(vector<int>&array,int count, int maximum){
        vector<int> result;
        recursive(result,array,0,0,count,maximum);
        return result;
    }
    
    void recursive(vector<int>&result,vector<int>&array,int index,int current,int count,int maximum){
        if(count==0 or index==array.size()){
            if(current<maximum and count==0){
                result.push_back(current);
            }
            return;
        }
        
        recursive(result,array,index+1,current,count,maximum);
        current+=array[index];
        if(current<maximum){
            recursive(result,array,index+1,current,count-1,maximum);
        }
    }
    
    vector<string> combine(vector<int>&hours, vector<int>&minutes){
        vector<string> result;
        for(int i=0;i<hours.size();++i){
            for(int j=0;j<minutes.size();++j){
                result.push_back(get(hours[i],minutes[j]));
            }
        }
        return result;
    }
    
    string get(int hour,int minute){
        string result="";
        result+=toString(hour,0);
        result+=":";
        result+=toString(minute,1);
        return result;
    }
    
    string toString(int num,int type){
        string result="";
        while(num){
            result.push_back('0'+num%10);
            num/=10;
        }
        if(type==1 and result.size()<2){
            while(result.size()!=2){
                result.push_back('0');
            }
        }else{
            if(result=="")
                result.push_back('0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
