class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> safe( n , vector<bool>(m,false) );
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){ 
            if(board[i][0]=='O'){
                safe[i][0]=true;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                safe[i][m-1]=true;
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){ 
            if(board[0][j]=='O'){
                safe[0][j]=true;
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                safe[n-1][j]=true;
                q.push({n-1,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            auto [i,j]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
                if(board[ni][nj]!='O'||safe[ni][nj]) continue;
                safe[ni][nj]=true;
                q.push({ni,nj});
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='O'|| safe[i][j]) continue;
                board[i][j]='X';
            }
        }
    }

};
