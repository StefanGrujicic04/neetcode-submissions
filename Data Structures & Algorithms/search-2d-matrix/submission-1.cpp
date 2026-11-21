class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m= matrix[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int n1=mid/m;
            int m1=mid%m;
            if(matrix[n1][m1]>target)
                high=mid-1;
            else if(matrix[n1][m1]<target)
                low=mid+1;
            else
                return true;
        }
        return false;
    }
};
