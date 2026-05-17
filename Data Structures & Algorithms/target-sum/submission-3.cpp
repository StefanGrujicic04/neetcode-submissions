class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int num: nums)total+=num;
        if((total+target)%2 !=0 || total+target<0)return 0;
        int p=(total+target)/2;
        vector<int> dp(p+1,0);
        dp[0]=1;
        for(int num: nums){
            for(int i=p;i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[p];
    }

};
