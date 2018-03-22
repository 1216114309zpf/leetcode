class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> vec(s1.size()+1,0);
        vector<vector<int>> matrix(s2.size()+1,vec);
        for(int i=1;i<=s1.size();++i){
            matrix[0][i]=matrix[0][i-1]+s1[i-1];
        }
        for(int j=1;j<=s2.size();++j){
            matrix[j][0]=matrix[j-1][0]+s2[j-1];
        }
        for(int i=1;i<=s2.size();++i){
            for(int j=1;j<=s1.size();++j){
                if(s1[j-1]==s2[i-1]){
                    matrix[i][j]=min(matrix[i-1][j]+s2[i-1],matrix[i][j-1]+s1[j-1],matrix[i-1][j-1]);
                }else{
                    matrix[i][j]=min(matrix[i-1][j]+s2[i-1], matrix[i][j-1]+s1[j-1]);
                }
            }
        }
        return matrix[s2.size()][s1.size()];
    }
    
    int min(int a,int b,int c){
        if(a<b){
            return min(a,c);
        }else{
            return min(b,c);
        }
    }
    
    int min(int a,int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
    }
};
