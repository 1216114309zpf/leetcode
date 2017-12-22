class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int * array=new int[temperatures.size()];
        int index = temperatures.size()-1;
        array[index] = 0;
        for(int i=index-1; i>=0; --i){
            if(temperatures[i] >= temperatures[index]){
                array[i] = 0;
                index = i;
            }
            
            for(int j=i+1; j<=index; ++j){
                if(temperatures[j] > temperatures[i]){
                    array[i]=j-i;
                    break;
                }
            }
        }
        
        vector<int> result;
        for(int i=0; i<temperatures.size(); ++i)
            result.push_back(array[i]);
        return result;
    }
};
