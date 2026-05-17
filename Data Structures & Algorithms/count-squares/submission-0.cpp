class CountSquares {
    map<pair<int,int>,int> cnt;
    vector<pair<int,int>> dots;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[{point[0],point[1]}]++;
        dots.push_back({point[0],point[1]});
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int ans = 0;

        for (auto& [x, y] : dots) {
            if (abs(px - x) != abs(py - y) || px == x || py == y)
                continue;

            ans += cnt[{px, y}] * cnt[{x, py}];
        }
        return ans;
    }
};
