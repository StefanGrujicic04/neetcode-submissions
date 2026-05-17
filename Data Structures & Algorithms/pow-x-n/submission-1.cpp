class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n<0){
            x=1.0/x;
            n=-n;
        }
        return myPow(x*x ,n/2) * (n%2 ? x : 1);
    }
};
