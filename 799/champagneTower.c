class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> vec;
        vector<double> tmp;
        for(int i=0;i<=query_row;i++){
            tmp.push_back(-1.0);
            vec.push_back(tmp);
        }
        
        double total=help(poured, query_row, query_glass,vec);
        if(total>1)
            return 1.0;
        else{
            return total;
        }
    }
    
    double help(int poured, int query_row, int query_glass,vector<vector<double>>&vec){
        if(vec[query_row][query_glass]>=0){
            return vec[query_row][query_glass];
        }
        
        if(query_row==0){
            return vec[query_row][query_glass]=poured;
        }
        
        int left=query_glass-1;
        int right=query_glass;
        double result=0.0;
        if(left>=0 and left<=query_row-1){
            double l=help(poured, query_row-1, left,vec);
            if(l>1)
               result+=(l-1)/2.0;
        }
        if(right>=0 and right<=query_row-1){
            double r=help(poured,query_row-1,right,vec);
            if(r>1)
            result+=(r-1)/2.0;
        }
        return vec[query_row][query_glass]=result;
    }
};
