class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool firstRowZeros=false;
        bool firstColumnZeros=false;
        for(int i=0;i<m;i++)
            firstRowZeros=firstRowZeros || matrix[0][i]==0;

        for(int i=0;i<n;i++)
            firstColumnZeros=firstColumnZeros || matrix[i][0]==0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!matrix[i][j]){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }        
            }
        }
        for(int i=1;i<n;i++){
            if(!matrix[i][0]){
                for(int j=0;j<m;j++)
                    matrix[i][j]=0;
            }
        }
        for(int j=1;j<m;j++){
            if(!matrix[0][j]){
                for(int i=0;i<n;i++)
                    matrix[i][j]=0;
            }
        }
        if(firstRowZeros){
            for(int i=0;i<m;i++)
                matrix[0][i]=0;
        }
        if(firstColumnZeros){
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    }
};
