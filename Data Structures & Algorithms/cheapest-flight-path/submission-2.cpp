class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>  airports(n,INT_MAX);
        airports[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int>tmp(airports);
            bool changed=false;
            for(auto & flight: flights){
                if(airports[flight[0]]!=INT_MAX &&airports[flight[0]]+ flight[2]< tmp[flight[1]] )
                {
                    tmp[flight[1]]=airports[flight[0]]+ flight[2];
                    changed=true;
                }
            }
            if(!changed)
                break;
            airports=tmp;
        }
        return airports[dst]==INT_MAX? -1: airports[dst];

    }
};
