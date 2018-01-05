class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left=0;
        long long  right=num;
        while(left<=right){
            if(left==right){
                if(left*left==num)
                    return true;
                else
                    return false;
            }
            long long  mid = (left+right)/2;
            if(mid*mid>num)
                right=mid;
            else if(mid*mid==num)
                return true;
            else
                left=mid+1;
        }
    }
};
