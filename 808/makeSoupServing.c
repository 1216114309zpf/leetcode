class Solution {
public:
    double soupServings(int N) {
        if(N>10000)
            return 1.0;
        unordered_map<long long  int, double> mymap;
        return help(N,N,mymap);
    }
    
    double help(int A, int B,unordered_map<long long  int,double>& mymap){
        long long int index=(long long int)(A)*1000000000+B;
        if(mymap.count(index)!=0){
            return mymap[index];
        }
        
        if(A<=0){
            if(B<=0)
                return mymap[index]=0.5;
            else
                return  mymap[index]=1.0;
        }
        
        if(B<=0){
            return mymap[index]=0;
        }
        
        double result=0.0;
        result+=0.25*help(A-100,B,mymap);
        result+=0.25*help(A-75,B-25,mymap);
        result+=0.25*help(A-50,B-50,mymap);
        result+=0.25*help(A-25,B-75,mymap);
        return mymap[index]=result;
    }
};
