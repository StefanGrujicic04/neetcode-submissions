class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            paths[i][0]=1;
        for(int j=0;j<m;j++)
            paths[0][j]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++)
                paths[i][j]=paths[i-1][j]+paths[i][j-1];
        }
        return paths[n-1][m-1];
    }
};
