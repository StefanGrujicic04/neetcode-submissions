class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    continue;
                solve(grid,i,j,0);
            }
        }
    }
    void solve(vector<vector<int>>&  grid,int i,int j,int curr){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return ;
        if(grid[i][j]==-1)return;
        if(grid[i][j]<curr)return;
        grid[i][j]=curr;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            solve(grid,i+dx[k],j+dy[k],curr+1);
        }
    }
};
