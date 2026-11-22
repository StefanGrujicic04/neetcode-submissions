class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        if(size==1)return 0;
        if(size==2)return nums[0]>nums[1]? 0:1;
        int mid= (nums.size()-1)/2;
        while(mid>0&& mid<size-1){
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;
            else if(nums[mid]<nums[mid+1])
                mid=mid+1;
            else if(nums[mid]<nums[mid-1])
                mid=mid-1;
            else
                mid=mid-1;
            
        }
        if(mid==0 || mid==size-1)
            return mid;
        return -1;
    }
};