class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxSeq=1;
        vector<int>subseq(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    subseq[i]=max(subseq[j]+1,subseq[i]);
            }
            maxSeq=max(subseq[i],maxSeq);
        }
        return maxSeq;
        
    }
};
