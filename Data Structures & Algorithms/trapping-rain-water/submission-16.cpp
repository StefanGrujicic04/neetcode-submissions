class Solution {
public:
    int trap(vector<int>& heights) {
        int size=heights.size();
        int water=0;
        int left=0,right=size-1;
        int max_left=0,max_right=0;
        while(left<right){
            if(heights[left]<heights[right]){
                max_left=max(max_left,heights[left]);
                water+=max_left-heights[left];
                left++;
            }else
            {
                max_right=max(max_right,heights[right]);
                water+=max_right-heights[right];
                right--;
            }
        }
        return water;

        
    }
};
