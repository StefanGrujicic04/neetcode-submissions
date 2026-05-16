class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<int>found;
        found.push_back(0);
        for(int i=0;i<s.size();i++){
            for(int start:found){
                if(dict.count(s.substr(start,i-start+1))){
                    found.push_back(i+1);
                    break;
                }
            }
        }
        if(found[found.size()-1]!=s.size())
            return false;
        return true;
    }
};
