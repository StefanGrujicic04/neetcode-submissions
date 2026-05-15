class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> needs(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& p: prerequisites){
            needs[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> q;
        vector<int> result;
        for(int i=0;i<numCourses;i++){
            if(needs[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i=q.front();q.pop();
            result.push_back(i);
            for(int course: adj[i]){
                if(--needs[course]==0 )
                    q.push(course);
            }
        }
    if(result.size()!=numCourses)
        return {};
    return result;

    }
};
