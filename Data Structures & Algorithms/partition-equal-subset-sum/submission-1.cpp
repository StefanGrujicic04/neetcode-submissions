class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumPart=0;
        int n=nums.size();
        for(int i=0;i<n;i++)sumPart+=nums[i];
        if(sumPart&1) return false;
        sumPart=sumPart>>1;
        vector<bool> sums(sumPart+1,false);
        sums[0]=true;
         for(int num:nums)
         {
            for(int i=sumPart;i>=num;i--)
            {   
                sums[i]=sums[i]||sums[i-num];
            }
        }
        return sums[sumPart];
        
    }
};
