class Solution {
public:
    int find(int x,vector<int>& parent){
        if(parent[x]!=x)
            parent[x]=find(parent[x],parent);
        return parent[x];    
    }
    bool unite(int x,int y,vector<int>&  parent,int&  components){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py) return false;
        parent[py]=px;
        components--;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1!=edges.size()) return false;
        vector<int> parent(n);
        int components=n; 
        iota( parent.begin(),parent.end(),0 ); 
        for(auto& edge: edges){
                if (!unite(edge[0], edge[1], parent, components))
                    return false; 
        }
        if(components!=1)
            return false;
        return true;
    }
};
