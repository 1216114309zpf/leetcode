class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.size()<2)
            return true;
        unordered_map<string,vector<string>> mymap;
        for(int i=0;i<allowed.size();++i){
            string value="";
            value.push_back(allowed[i][allowed[i].size()-1]);
            allowed[i].pop_back();
            mymap[allowed[i]].push_back(value);
        }
        
        string current="";
        if(canTransmit(bottom,mymap,current,0)){
            return true;
        }
        return false;
    }
    
    bool canTransmit(string bottom, unordered_map<string,vector<string>>&mymap,string current,int index){
        if(bottom.size()<2){
            return true;
        }
        
        if(bottom.size()==2){
            if(mymap.count(bottom)==0){
                return false;
            }
            return true;
        }
        
        //for(int i=index;i<bottom.size()-1;++i){
            string tmp="";
            tmp.push_back(bottom[index]);
            tmp.push_back(bottom[index+1]);
            if(mymap.count(tmp)==0){
                return false;
            }else{
                for(int j=0;j<mymap[tmp].size();++j){
                    string str=current+mymap[tmp][j];
                    if(index==bottom.size()-2){
                        if(canTransmit(str,mymap,"",0))
                            return true;
                    }else{
                         if(canTransmit(bottom,mymap,str,index+1))
                             return true;
                    }
                }
            }
            
       // }
        
        return false;
    }
};
