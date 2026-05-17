class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N==0) return 1;
        if(N==1) return x;
        if(N<0){
            x=1.0/x;
            N=-N;
        }
        return helper(x*x ,N/2) * (N%2 ? x : 1);
    }
    double helper(double x,int n){
        if (n == 0) return 1;
        if (n == 1) return x;
        return helper(x * x, n / 2) * (n % 2 ? x : 1);
    }
};
