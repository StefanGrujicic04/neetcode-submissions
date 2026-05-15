class Solution {
public:
    int find(int x,vector<int>& parent){
        if(parent[x]!=x)
            parent[x]=find(parent[x],parent);
        return parent[x];
    }
    bool unite(int x, int y, vector<int>& parent, int& components){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py)return false;
        parent[py]=px;
        components--;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int components=n;
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        int i=0;
        for(;i<n;i++){
            if(! unite( edges[i][0]-1,edges[i][1]-1,parent,components ) )
                break;
        }
        return edges[i];
    }
};
