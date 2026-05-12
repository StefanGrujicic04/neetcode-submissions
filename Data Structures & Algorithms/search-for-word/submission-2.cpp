class Solution {
    int n,m;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this-> n=board.size();
        this-> m=board[0].size();
        bool result=false;
        for(int i=0;i<n && !result;i++){
            for(int j=0;j<m && !result;j++){
                if(board[i][j]==word[0])
                    result=result || solve(board,i,j,word,0);

            }
        }
        return result;
    }
    bool solve(vector<vector<char>>& board,int i, int j, string & word, int curr){
        if(board[i][j]==word[curr])
            curr++;
        else
            return false;
        if(curr==word.size()){
            return true;
        }
        bool solved=false;
        char tmp=board[i][j];
        board[i][j]='#';
        if(i+1<n )
            solved=solved || solve(board,i+1,j,word,curr);

        if(j+1<m)
            solved=solved || solve(board,i,j+1,word,curr);

        if(i-1>=0)
            solved=solved || solve(board,i-1,j,word,curr);

        if(j-1>=0)
            solved=solved || solve(board,i,j-1,word,curr);  
            
        board[i][j]=tmp;

        return solved;
    }
};
