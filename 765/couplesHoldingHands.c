class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int result=0;
        unordered_map<int,int> myMap;
        for(int i=0;i<row.size();++i){
            myMap[row[i]]=i;
        }
        for(int i=0;i<row.size();i+=2){
            int item=row[i];
            int another=(item%2)?item-1:item+1;
            if(row[i+1]==another){
                continue;
            }else{
                ++result;
                int tmp=row[i+1];
                row[i+1]=another;
                row[myMap[another]]=tmp;
                int t=myMap[another];
                myMap[another]=i+1;
                myMap[tmp]=t;
            }
        }
        return result;
    }
};
