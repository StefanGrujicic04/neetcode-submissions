class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxH;
        for(int stone: stones){
            maxH.push(stone);
        }
        while(maxH.size()>1){
            int x=maxH.top();
            maxH.pop();
            int y=maxH.top();
            maxH.pop();
            x-=y;
            if(x){
                maxH.push(x);
            }
        }
        if(maxH.empty())
            return 0;
        return maxH.top();
    }
};
