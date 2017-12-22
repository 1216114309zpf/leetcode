class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int *array = new int[cost.size()+1];
        array[0]=0;
        array[1]=0;
        for(int i=2; i<cost.size()+1; ++i){
            int first = array[i-2] + cost[i-2];
            int second = array[i-1] + cost[i-1];
            array[i]=(first>second)?second:first;
        }
        return array[cost.size()];
    }
};
