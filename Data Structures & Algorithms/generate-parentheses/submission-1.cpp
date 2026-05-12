class Solution {
    int n;
public:
    vector<string> generateParenthesis(int n) {
        this->n=n;
        vector<string> result;
        string curr;
        solve(0,0,0,curr,result);
        return result;
    }
    void solve( int i,int open,int close,string& curr,vector<string>& result){
        if(i==n*2){

            result.push_back(curr);
            return;
        }
        if(open>close){
            curr.push_back(')');
            solve(i+1,open,close+1,curr,result);
            curr.pop_back();
        }
        if(open<n){
            curr.push_back('(');
            solve(i+1,open+1,close,curr,result);
            curr.pop_back();
        }
    }
};
