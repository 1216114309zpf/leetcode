class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int *array = new int[10001];
        int *result = new int[10001];
        for(int i=0; i<10001; ++i){
            array[i] = 0;
            result[i] = 0;
        }
        for(int i=0; i<nums.size(); ++i)
            ++array[nums[i]];
        
        result[1] = array[1];
        for(int i=2; i<10001; ++i){
            int first = result[i-2] + array[i] * i;
            int second = result[i-1] + array[i] * i - array[i-1]*(i-1);
            int third = result[i-1];
            result[i] = max(first, second, third);
        }
        return result[10000];
    }
    
    int max(int a, int b, int c){
        if(a > b)
            return max(a, c);
        else
            return max(b,c);
    }
    int max(int a, int b){
        if(a>b)
            return a;
        else
            return b;
    }
};
