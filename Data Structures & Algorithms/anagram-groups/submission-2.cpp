class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        vector<vector<string>> result;
        for(auto word : strs){
            string current_word=word;
            sort(current_word.begin(),current_word.end());
            groups[current_word].push_back(word);
        }
        for(auto p : groups){
            result.push_back(p.second);
        }
        return result;
    }
};
