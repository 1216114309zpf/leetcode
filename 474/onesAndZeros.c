class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        sort(strs.begin(),strs.end(),cmp);
        vector<int> tmp(m+1,-1);
        vector<vector<int>> matrix(n+1,tmp);
        vector<vector<vector<int>>> cube(strs.size(),matrix);
        help(strs,0,cube,m,n);
        return cube[0][n][m];
    }
    
    int help(vector<string>& strs,int current,vector<vector<vector<int>>> &cube,int zeros, int ones ){
        if(current==strs.size())
            return 0;
        
        if(cube[current][ones][zeros]!=-1){
            return cube[current][ones][zeros];
        }
        
        int one,zero;
        get(strs[current],zero,one);
        
        int with=0;
        if(zeros>=zero and ones>=one){
            with=1+help(strs,current+1,cube,zeros-zero,ones-one);
        }
        
        int without=help(strs,current+1,cube,zeros,ones);
        
        return cube[current][ones][zeros]=max(with,without);
    }
    
    static bool cmp(string a, string b){
        return a.size()<b.size();
    }
    
    void get(string str, int &zero, int &one){
        zero=0;
        one=0;
        for(int i=0;i<str.size();++i){
            if(str[i]=='0')
                ++zero;
            else
                ++one;
        }
    }
};
