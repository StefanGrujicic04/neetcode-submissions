class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i){
                if(nums[nums[i]]==nums[i])
                    return nums[i];
                swap(nums[nums[i]],nums[i]);
            }
            else
                i++;
        }
    }
};
