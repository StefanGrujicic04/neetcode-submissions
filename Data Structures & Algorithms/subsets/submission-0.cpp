class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int>curr_result;
        backtracking(nums,0,curr_result,results);
        return results;
    }
    void backtracking(vector<int>& nums,int i,vector<int>curr_result,vector<vector<int>>& results){
        if(i==nums.size()){
            results.push_back(curr_result);
            return;
        }
        i++;
        backtracking(nums,i,curr_result,results);
        curr_result.push_back(nums[i-1]);
        backtracking(nums,i,curr_result,results);    
    }
};
