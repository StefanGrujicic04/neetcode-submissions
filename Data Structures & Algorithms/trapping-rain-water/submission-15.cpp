class Solution {
public:
    int trap(vector<int>& heights) {
        int size=heights.size();
        vector<int> max_left(heights.size(),0);
        vector<int> max_right(heights.size(),0);
        int left=heights[0];
        int right=heights[size-1];
        int water=0;
        for(int i=1;i<size;i++){
            max_left[i]=left;
            left=max(left,heights[i]);
        }
        for(int i=size-2;i>=0;i--){
            max_right[i]=right;
            right=max(right,heights[i]);
        }
        for(int i=0;i<size;i++){
            int curr_max=min(max_left[i],max_right[i]);
            if(curr_max> heights[i])
                water+=curr_max-heights[i];
        }
        return water;

        
    }
};
