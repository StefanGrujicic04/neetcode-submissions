class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> solution;
        int size=nums.size();
        for(int i=0;i<size-2;i++){
            if(i!=0 &&  nums[i]==nums[i-1])
                continue;
            int pivot=nums[i];
            int high=size-1;
            int low=i+1;
            while(low<high){
                int sum=nums[low]+nums[high]+pivot;
                if(sum > 0){
                    high--;
                }else if(sum < 0){
                    low++;
                }else {
                    solution.push_back({pivot,nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[low]== nums[low-1])
                        low++;
                    while(high>low && nums[high]==nums[high+1])
                        high--;
                }
            }
        }
        return solution;
    }
};
