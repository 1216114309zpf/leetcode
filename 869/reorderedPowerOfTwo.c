class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> number = toVector(N);
        sort(number.begin(),number.end());
        int current = 1;
        for(int i=0;i<32;i++){
            vector<int> tmp = toVector(current);
            sort(tmp.begin(),tmp.end());
            if(tmp == number){
                return true;
            }
            current*=2;
        }
        return false;
    }
    vector<int> toVector(int number){
        vector<int> result;
        if(number==0){
            result.push_back(0);
            return result;
        }
        while(number){
            result.push_back(number%10);
            number/=10;
        }
        return result;
    }
};
