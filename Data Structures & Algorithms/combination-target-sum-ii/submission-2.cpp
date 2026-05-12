class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,curr,target,result);
        return result;
        
    }
    void solve(vector<int>& cand,int i,vector<int>& curr, int target, vector<vector<int>>& result){
        if(!target){
            result.push_back(curr);
            return;
        }
        for(int j=i;j<cand.size();j++){
            if(cand[j]>target)
                break;
            if(j>i&&cand[j-1]==cand[j])
                continue;
            curr.push_back(cand[j]);
            solve(cand,j+1, curr, target-cand[j],result);
            curr.pop_back();
        }

    }
};
