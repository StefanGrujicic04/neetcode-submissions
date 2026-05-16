class Solution {
    
public:
     
    int numDecodings(string s) {
        auto oneDigitValid=[s](int i){
            if(s[i]-'0'>0&&s[i]-'0'<10)
                return true;
            return false;
        };
        auto twoDigitValid=[s](int i){
            if( (s[i-1]-'0')*10+s[i]-'0' > 9 && (s[i-1]-'0')*10+s[i]-'0' < 27 )
                return true;
            return false;
        };
        int n=s.size();
        int prev2=0;
        if(oneDigitValid(0))prev2++;
        if(n==1) return prev2;

        int prev1=0;
        if(oneDigitValid(1))prev1+=prev2;
        if(twoDigitValid(1))prev1++;
        for(int i=2;i<n;i++){
            int curr=0;
            if(oneDigitValid(i))curr+=prev1;
            if(twoDigitValid(i))curr+=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
