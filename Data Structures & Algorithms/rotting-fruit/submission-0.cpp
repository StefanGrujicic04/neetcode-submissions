class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) { // bfs with multy start
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int curr=0;
        while(!q.empty()){
            int curr_size=q.size();
            bool pasted=false;
            for(int mm=0;mm<curr_size;mm++){
                auto [i,j]=q.front();
                q.pop();
                if(grid[i][j]!=2)
                    continue;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<0||ni>=n||nj<0||nj>=m)continue;
                    if(grid[ni][nj]!=1)continue;
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                    pasted=true;
                }

            }
            if(pasted)
                curr++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return curr;
    }
};
