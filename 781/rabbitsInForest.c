class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int ,int> myMap;
        for(int i=0;i<answers.size();++i){
            if(myMap.count(answers[i])!=0){
                ++myMap[answers[i]];
            }else{
                myMap[answers[i]]=1;
            }
        }
        
        int result=0;
        for(auto itr=myMap.begin();itr!=myMap.end();++itr){
            pair<int,int> term=*itr;
            while(term.second>term.first+1){
                result+=(term.first+1);
                term.second-=(term.first+1);
            }
            if(term.second!=0)
                result+=(term.first+1); 
        }
        return result;
    }
};
