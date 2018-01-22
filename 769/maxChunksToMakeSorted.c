class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result=0;
        int target=arr[0];
        int currentPosition=0;
        while(target<arr.size()){
            while(currentPosition<=target){
                if(arr[currentPosition]<=target)
                    ++currentPosition;
                else 
                    target=arr[currentPosition];
            }
            ++result;
            ++target;
        }
        return result;
    }
};
