class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=nums[0];
        if(n==1)return prev2;
        int prev1=max(nums[1],prev2);
        if(n==2) return max(prev1,prev2);
        for(int i=2;i<n;i++){
            int curr=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return max(prev1,prev2);
    }
};
