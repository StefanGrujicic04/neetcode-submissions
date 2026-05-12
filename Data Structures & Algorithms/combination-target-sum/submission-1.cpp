class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backprop(nums,0,curr,target,result);
        return result;
    }
    void backprop(vector<int>& nums,int i, vector<int>& curr ,int target,vector<vector<int>>& result){
        if(!target){
            result.push_back(curr);
            return;
        }
        if(i==nums.size()){
            return;
        }

        backprop( nums,i+1,curr ,target,result);
        for(int j=1;j*nums[i]<=target;j++){
            curr.push_back(nums[i]);
            backprop( nums,i+1,curr ,target-j*nums[i],result);
        }
        for(int j=1;j*nums[i]<=target;j++)
            curr.pop_back();
    }
};
