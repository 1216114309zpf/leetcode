class Solution {
public:
    int minDistance(string word1, string word2) {
        int **array = new int*[word1.size()+1];
        for(int i=0;i<word1.size()+1;++i){
            array[i]=new int[word2.size()+1];
        }
        
        array[0][0]=0;
        for(int i=1;i<word1.size()+1;++i){
            array[i][0]=i;
        }
        for(int j=1;j<word2.size()+1;++j){
            array[0][j]=j;
        }
        
        for(int i=1;i<word1.size()+1;++i){
            for(int j=1;j<word2.size()+1;++j){
                if(word1[i-1]==word2[j-1]){
                    array[i][j] = min(array[i-1][j-1],array[i-1][j]+1,array[i][j-1]+1);
                }else{
                    array[i][j] = min(array[i-1][j-1]+2,array[i-1][j]+1,array[i][j-1]+1);
                }
            }
        }
        return array[word1.size()][word2.size()];
    }
    
    int min(int a,int b,int c){
        if(a<b)
            return (a<c)?a:c;
        else
            return (b<c)?b:c;
    }
};
