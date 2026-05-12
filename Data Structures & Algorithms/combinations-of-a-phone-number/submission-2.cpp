class Solution {
public:
    const string mapped[8] = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        string curr;
        solve(digits, 0, curr, result);
        return result;
    }

    void solve(const string& digits, int i, string& curr, vector<string>& result) {
        if (i == digits.size()) {
            result.push_back(curr);
            return;
        }
        for (char c : mapped[digits[i] - '2']) {
            curr.push_back(c);
            solve(digits, i + 1, curr, result);
            curr.pop_back();
        }
    }
};
