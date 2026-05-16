class Solution {
    class UnionFind{
        public:
        vector<int>parent,rank_;
        int components;
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        bool unite(int x,int y){
            int px=find(x);
            int py=find(y);
            if(px==py)return false;
            if(rank_[px]>rank_[py]){
                swap(px,py);
            }
            parent[px]=py;
            if(rank_[px]==rank_[py])
                rank_[py]++;
            components--;
            return true;
        }
        UnionFind(int n):parent(n),rank_(n,0),components(n) {
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
    };
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<array<int,3>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        UnionFind uf(n);
        int total=0;
        for(auto& [c,u,v]: edges){
            if(uf.unite(u,v)){
                total+=c;
            }
        }
        return total;
    }
};
