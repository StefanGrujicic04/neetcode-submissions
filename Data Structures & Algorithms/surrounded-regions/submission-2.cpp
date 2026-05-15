class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){ 
            if(board[i][0]=='O'){
                board[i][0]='S';
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='S';
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){ 
            if(board[0][j]=='O'){
                board[0][j]='S';
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                board[n-1][j]='S';
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
                if(board[ni][nj]!='O') continue;
                board[ni][nj]='S';
                q.push({ni,nj});
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='S')
                    board[i][j]='O';
            }
        }
    }

};
