class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0,high=nums.size()-1;
        int minimum=min(nums[low],nums[high]);
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[low]<nums[mid]){
                low=mid;
            }else{
                minimum=min(minimum,nums[mid]);
                high=mid;
            }
        }
        return minimum;
    }
};
