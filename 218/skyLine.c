class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> result;
        if(buildings.size()==0)
            return result;
        return DivideAndConquer(buildings,0,buildings.size()-1);
    }
    
    vector<pair<int,int>> DivideAndConquer(vector<vector<int>>& buildings,int left,int right){
        vector<pair<int,int>> result;
        if(left==right){
            pair<int,int> start,end;
            start.first=buildings[left][0];
            start.second=buildings[left][2];
            end.first=buildings[left][1];
            end.second=0;
            result.push_back(start);
            result.push_back(end);
            return result;
        }
        
        int mid=left+(right-left)/2;
        vector<pair<int,int>> leftHalf=DivideAndConquer(buildings,left,mid);
        vector<pair<int,int>> rightHalf=DivideAndConquer(buildings,mid+1,right);
        
        int currentL=0;
        int currentR=0;
        
        int indexL=0;
        int indexR=0;
        while(indexL<leftHalf.size() and indexR<rightHalf.size()){
            if(leftHalf[indexL].first<rightHalf[indexR].first){
                if(leftHalf[indexL].second>currentL){
                    if(leftHalf[indexL].second>currentR){
                        result.push_back(leftHalf[indexL]);
                    }
                }else{
                    if(currentR>=currentL){
                        
                    }else if(currentR>=leftHalf[indexL].second){
                        result.push_back(leftHalf[indexL]);
                        result[result.size()-1].second=currentR;
                    }else{
                        result.push_back(leftHalf[indexL]);
                    }
                }
                currentL=leftHalf[indexL].second;
                ++indexL;
            }else if(leftHalf[indexL].first==rightHalf[indexR].first){
                currentL=leftHalf[indexL].second;
                currentR=rightHalf[indexR].second;
                pair<int,int> line;
                line.first=leftHalf[indexL].first;
                line.second=max(leftHalf[indexL].second,rightHalf[indexR].second);
                if(result.size()==0 or line.second!=result[result.size()-1].second)
                     result.push_back(line);
                ++indexL;
                ++indexR;
            }else{
                if(rightHalf[indexR].second>currentR){
                    if(rightHalf[indexR].second>currentL){
                        result.push_back(rightHalf[indexR]);
                    }
                }else{
                    if(currentL>=currentR){
                        
                    }else if(currentL>=rightHalf[indexR].second){
                        result.push_back(rightHalf[indexR]);
                        result[result.size()-1].second=currentL;
                    }else{
                        result.push_back(rightHalf[indexR]);
                    }             
                }
                currentR=rightHalf[indexR].second;
                ++indexR;
            }
        }
        
        while(indexL<leftHalf.size()){
            result.push_back(leftHalf[indexL]);
            ++indexL;
        }
        
        while(indexR<rightHalf.size()){
            result.push_back(rightHalf[indexR]);
            ++indexR;
        }
        return result;
    }
};
