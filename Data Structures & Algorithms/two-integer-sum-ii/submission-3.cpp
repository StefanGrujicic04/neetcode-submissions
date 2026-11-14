class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,0);
        int size= numbers.size();
        result[1]=size-1;
        while(true){
            int sum=numbers[result[0]]+numbers[result[1]];
            if(sum>target){
                result[1]--;
            }else if(sum<target )
                result[0]++;
            else
            {
                result[0]++;
                result[1]++;
                break;
            }
        }
        return result;
    }
};
