class Solution {
public:
    int robRange(vector<int>& nums,int lo,int hi){
        int prev2=0;
        int prev1=0;
        for(int i=lo;i<=hi;i++){
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return max(prev1,prev2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }
};
