class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int number=n;
        unsigned int com=1;
        bool flag=!(com&number);
        while(com<number){
            if(flag!=(!(com&number)))
                return false;
            else{
                flag=!flag;
                com<<=1;
            }
        }
        return true;
    }
};
