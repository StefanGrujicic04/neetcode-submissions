class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int final=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            final^=nums[i];
        }
        return final;
    }
};
