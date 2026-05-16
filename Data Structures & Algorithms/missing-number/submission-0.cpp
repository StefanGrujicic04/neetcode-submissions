class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int result=n*(n+1);
        result>>=1;
        for(int i=0;i<n;i++){
            result-=nums[i];
        }
        return result;
    }
};

