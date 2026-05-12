class Solution {
public:
    unordered_map<char,vector<char>> mapped = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}}
    };
    

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr="";
        if(!digits.empty())
            solve(digits,0,curr,result);
        return result;
    }
    void solve(const string& digits, int i,string& curr,vector<string>& result){
        if(i==digits.size()){
            result.push_back(curr);
        }
        for(char c: mapped[digits[i]]){
            curr.push_back(c);
            solve(digits,i+1,curr,result);
            curr.pop_back();
        }
    }
};
