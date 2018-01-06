class Solution {
public:
    int integerBreak(int n) {
        int *array=new int[n+1];
        array[1]=1;
        for(int i=2;i<n+1;++i){
            int maxi=0;
            for(int j=1;j<=i/2;++j){
                if(max(j,array[j])*max(i-j,array[i-j])>maxi)
                    maxi=max(j,array[j])*max(i-j,array[i-j]);
            }
            array[i]=maxi;
        }
        return array[n];
    }
};
