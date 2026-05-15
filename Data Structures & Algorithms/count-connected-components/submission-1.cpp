class Solution {
    
public:
    int find(int x,vector<int>& parent){
        if(parent[x]!=x){
            parent[x]=find(parent[x],parent);
        }
        return parent[x];
    }
    bool unite(int x,int y,vector<int>& parent,int& components){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py) return false;
        parent[py]=px;
        components--;
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        int components=n;
        for(auto& edge:edges){
            unite(edge[0],edge[1],parent,components);
        }
        return components;
    }
};
