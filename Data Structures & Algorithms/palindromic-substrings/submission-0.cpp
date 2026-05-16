class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int num=0;
        auto expand=[&](int l,int r){
            while( l>=0 && r<n && s[l]==s[r] ){
                num++;
                l--;
                r++;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i+1);
            expand(i,i);
        }
        return num;
    }
};
