class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> output(size,1);
        int prefix=nums[0];
        int sufix=nums[size-1];
        for(int i=1;i<size;i++){
            output[i]*=prefix;
            output[size-1-i]*=sufix;
            prefix*=nums[i];
            sufix*=nums[size-1-i];
        }
        return output;
    }
};
