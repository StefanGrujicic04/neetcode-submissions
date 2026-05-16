class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++){
            adj[ times[i][0] -1].push_back({times[i][2],times[i][1]-1});
        }
        vector<int> results(n,INT_MAX);
        int networkMax=0;
        int conections=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [v,c]=pq.top(); pq.pop();
            if(results[c]>v){
                conections++;
                results[c]=v;
                for(auto& adjs :adj[c]){
                    pq.push({adjs.first+v,adjs.second});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(results[i]==INT_MAX)return -1;
            networkMax=max(networkMax,results[i]);
        }
        return networkMax;
        
    }
};
