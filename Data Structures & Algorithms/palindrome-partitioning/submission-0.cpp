class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(s,0,curr,result);
        return result;
    }
    bool isPalin(string& s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string& s,int start,vector<string>& curr,vector<vector<string>>& result){
        if(start==s.size()){
            result.push_back(curr);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(isPalin(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                solve(s,end+1,curr,result);
                curr.pop_back();
            }
        }
    }

};
