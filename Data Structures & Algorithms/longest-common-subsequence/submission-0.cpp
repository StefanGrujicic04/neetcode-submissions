class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string & s1=text1;
        string & s2=text2;
        if(s1.size()>s2.size())
            swap(s1,s2);
        vector<int>dp(s2.size()+1,0);
        for(int i=1;i<=s1.size();i++){
            int prev=0;
            for(int j=1;j<=s2.size();j++){
                int tmp=dp[j];
                if(s2[j-1]==s1[i-1]){
                    dp[j]=prev+1;
                }
                else 
                    dp[j]=max(dp[j],dp[j-1]);
                prev=tmp;
            }
        }
        return dp[s2.size()];
    }
};
