class Solution {
public:
    bool test (const  vector<int>& piles, int h, int curr){
        long long count=0;
        for(const auto & pile : piles){
            count+=pile/curr;
            count+=pile%curr!=0 ? 1: 0;
        }
        return count<=h ? true: false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        if(test(piles,h,low))return low;
        int high=piles[0];
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int minimum=high;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(test(piles,h,mid)){
                minimum=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minimum;
    }
};
