class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            priority_queue<pair<int,int>> repetisons;
            unordered_map<int,int>unordered_rep;
            vector<int> results;
            for(const auto & num : nums){
                if(!unordered_rep.count(num))
                    unordered_rep[num]=1;
                else
                    unordered_rep[num]++;
            }
            for(const auto &[k,v] : unordered_rep)
                repetisons.push({v,k});
            for(int i=0;i<k;i++){
                int k= repetisons.top().second;
                repetisons.pop();
                results.push_back(k);
            }
            return results;
    }
};
