class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=cost[0];
        int prev1=cost[1];
        if(n==2) return min(prev2,prev1);
        for(int i=2;i<n;i++){
            int curr=min(prev2,prev1)+cost[i];
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
};
