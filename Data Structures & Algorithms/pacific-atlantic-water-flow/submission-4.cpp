class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> results;
        vector<vector<pair<bool,bool>>> oceans(n,vector<pair<bool,bool>>(m,{false,false}));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){ oceans[i][0].first=true; q.push({i,0}); }
        for(int i=0;i<m;i++){ oceans[0][i].first=true; q.push({0,i}); }

        for(int i=0;i<n;i++){ oceans[i][m-1].second=true; q.push({i,m-1});}
        for(int i=0;i<m;i++){ oceans[n-1][i].second=true; q.push({n-1,i});}
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            auto [i,j]=q.front(); q.pop();
            if(oceans[i][j].first==true){
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<0||nj<0||ni>=n||nj>=m)
                        continue;
                    if(heights[ni][nj]>=heights[i][j] && !oceans[ni][nj].first){
                        oceans[ni][nj].first=true;
                        q.push({ni,nj});
                        
                    }

                }
            }
            if(oceans[i][j].second==true){

                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<0||nj<0||ni>=n||nj>=m)
                        continue;
                    if(heights[ni][nj]>=heights[i][j]&&!oceans[ni][nj].second){
                        oceans[ni][nj].second=true;
                        q.push({ni,nj});
                    }

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(oceans[i][j].first&&oceans[i][j].second)
                    results.push_back({i,j});
            }
        }
        return results;
    }
};
