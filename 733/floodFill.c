ass Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> que;
        que.push(pair<int,int>(sr,sc));
        int old=image[sr][sc];
        while(!que.empty()){
            pair<int,int> pixel=que.front();
            que.pop();
            image[pixel.first][pixel.second]=-newColor;
            if(pixel.first>0 and image[pixel.first-1][pixel.second]==old){
                que.push(pair<int,int>(pixel.first-1,pixel.second));
            }
            if(pixel.first+1<image.size() and image[pixel.first+1][pixel.second]==old){
                que.push(pair<int,int>(pixel.first+1,pixel.second));
            }
            if(pixel.second>0 and image[pixel.first][pixel.second-1]==old){
                que.push(pair<int,int>(pixel.first,pixel.second-1));
            }
            if(pixel.second+1<image[0].size() and image[pixel.first][pixel.second+1]==old){
                que.push(pair<int,int>(pixel.first,pixel.second+1));
            }
        }
        for(int i=0;i<image.size();++i){
            for(int j=0;j<image[i].size();++j){
                image[i][j]=abs(image[i][j]);
            }
        }
        return image;
    }
}
