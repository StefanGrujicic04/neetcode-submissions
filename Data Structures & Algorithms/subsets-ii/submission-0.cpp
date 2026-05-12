class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,0,curr,result);
        return result;
    }
    void solve(vector<int>& nums,int i,vector<int>& curr,vector<vector<int>>& result ){
        for(int j=i;j<nums.size();j++){
            if(j>i&&nums[j]==nums[j-1])
                continue;
            curr.push_back(nums[j]);
            solve(nums,j+1, curr,result);
            curr.pop_back();
        }
        result.push_back(curr);
    }
};
