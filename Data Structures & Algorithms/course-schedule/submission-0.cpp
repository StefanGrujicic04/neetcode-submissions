class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>treba(numCourses,0);
        for(auto & p:prerequisites ){
            adj[p[1]].push_back(p[0]);
            treba[p[0]]++;
        }
        queue<int>q;
        int obradjen=0;
        for(int i=0;i<numCourses;i++){
            if(!treba[i]){
                q.push(i);
            } 
        }
        while(!q.empty()){
            int i=q.front(); q.pop();
            obradjen++;
            for(int course: adj[i]){
                if(--treba[course]==0)
                    q.push(course);
            }
        }
        return obradjen==numCourses;
    }
};
