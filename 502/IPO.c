class Solution {
    struct Project{
        int profit;
        int capital;
        Project(int profit,int capital):profit(profit),capital(capital){}
        Project(const Project&a) {
            profit=a.profit;
            capital=a.capital;
        }
        bool operator<(Project a) const {
            return profit < a.profit;
        }
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<Project> projects;
        for(int i=0;i<Profits.size();++i){
            Project pjt(Profits[i],Capital[i]);
            projects.push_back(pjt);
        }
        
        sort(projects.begin(),projects.end(),compare);
        
         // for(int i=0;i<projects.size();++i)
         //     cout<<projects[i].profit<<" "<<projects[i].capital<<endl;
        
        priority_queue<Project,vector<Project>,less<Project>> que;
        
        int itr=0;
        while(itr<projects.size()){
            while(itr<projects.size() and projects[itr].capital <= W){
                Project pjt(projects[itr].profit,projects[itr].capital);
                que.push(pjt);
                ++itr;
            }
            
            if(!que.empty() and k>0){
                Project pjt(que.top());
                W+=pjt.profit;
                que.pop();
                //cout<<pjt.profit<<endl;
                --k;
            }else{
                break;
            }
        }
        
        while(k>0){
            if(!que.empty()){
                Project pjt(que.top());
                W+=pjt.profit;
                que.pop();
                //cout<<pjt.profit<<endl;
                --k;
            }else{
                break;
            }
        }
        return W;
    }
    
    static bool compare(Project&a, Project&b){
        return a.capital < b.capital;
    }
};
