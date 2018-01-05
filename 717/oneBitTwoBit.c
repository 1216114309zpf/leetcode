class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1)
            return true;
        if(!canParse(bits))
            return true;
        else
            return false;
    }
    
    bool canParse(vector<int>&bits){
        if(bits[bits.size()-2]==0)
            return false;
        if(bits.size()==2)
            return true;
        bool *array=new bool[bits.size()-2];
        if(bits[0]==0)
            array[0]=true;
        else
            array[0]=false;
        for(int i=1;i<bits.size()-2;++i){
            if(bits[i]==0)
                array[i]=true;
            else{
                if(bits[i-1]==1 and (i==1 or array[i-2]))
                    array[i]=true;
                else
                    array[i]=false;
            }
        }
        if(array[bits.size()-3])
            return true;
        else
            return false;
    }
};
