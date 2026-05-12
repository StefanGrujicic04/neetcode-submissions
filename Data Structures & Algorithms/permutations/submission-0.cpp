class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> curr(nums.size(),-11);
        solve(nums,0, curr,results);
        return results;
    }
    void solve(vector<int>& nums,int i, vector<int>& curr,vector<vector<int>>&results){
        if(i==nums.size()){
            results.push_back(curr);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(curr[j]!=-11)
                continue;
            curr[j]=nums[i];
            solve(nums,i+1, curr,results);
            curr[j]=-11;
        }

    }
};
