class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j])
                    continue;
                int curr_size=0;
                dfs(grid,i,j,curr_size);
                if(curr_size>result)
                    result=curr_size;
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& grid, int i, int j ,int& curr_size){
        if(i<0|| i>=grid.size()|| j<0 || j>=grid[0].size()) return;
        if(!grid[i][j])return;
        grid[i][j]=0;
        curr_size++;
        int dx[]= {0,0,-1,1};
        int dy[]= {1,-1,0,0};
        for(int k=0;k<4;k++){
            dfs(grid,i+dx[k],j+dy[k],curr_size);
        }
    }
};
