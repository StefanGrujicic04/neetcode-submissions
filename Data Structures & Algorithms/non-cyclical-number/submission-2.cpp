class Solution {
public:
    int giveSq(int n){
        int k=0;
        while(n>0){
            k+=(n%10)*(n%10);
            n/=10;
        }
        return k;
    }
    bool isHappy(int n) {
        unordered_set<int> sumOfSq;
        int k;
        while(n!=1){
            k=giveSq(n);
            if(sumOfSq.count(k))return false;
            sumOfSq.insert(k);
            n=k;
        }
        return true;
    }
};
