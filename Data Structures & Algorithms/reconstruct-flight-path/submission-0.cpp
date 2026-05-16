class Solution {
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string>result;
public:
    void dfs(string airport){
        while(!adj[airport].empty()){
            string dest=adj[airport].top(); adj[airport].pop();
            dfs(dest);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket:tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
