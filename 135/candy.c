class Solution {
public:
    int candy(vector<int>& ratings) {
        int *array=new int[ratings.size()];
        array[0]=1;
        for(int i=1;i<ratings.size();++i){
            if(ratings[i]>ratings[i-1]){
                array[i]=array[i-1]+1;
            }else{
                array[i]=1;
            }
        }
    
        for(int i=ratings.size()-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                array[i]=max(array[i],array[i+1]+1);
            }
        }
        int result=0;
        for(int i=0;i<ratings.size();++i)
            result+=array[i];
        return result;
    }
};
