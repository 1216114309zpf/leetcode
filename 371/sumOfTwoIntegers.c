class Solution {
public:
    int getSum(int a, int b) {
        unsigned int AND = a&b;
        unsigned int XOR = a^b;
        while(AND!=0){
            AND<<=1;
            a=AND;
            b=XOR;
            AND = a&b;
            XOR = a^b;
        }
        
        return XOR;
    }
};
