class Solution {
public:
    int maxArea(vector<int>& heights) {
        int our_max=0;
        int size=heights.size();
        int low=0;
        int high=size-1;
        while(low<high){
            our_max=max(our_max,(high-low)*min(heights[high],heights[low]));
            if(heights[high]>heights[low]){
                low++;
            }
            else{
                high--;
            }
        }
        return our_max;
    }
};
