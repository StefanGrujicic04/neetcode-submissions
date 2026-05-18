/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> interval;
        for(auto & [x,y]:intervals){
            interval.push_back({x,y});
        }
        sort(interval.begin(),interval.end());
        for(int i=1;i<interval.size();i++){
            if(interval[i].first<interval[i-1].second) return false;
        }
        return true;
    }
};
