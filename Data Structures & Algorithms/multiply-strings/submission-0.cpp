class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;

                int sum = mul + result[p2];
                result[p2] = sum % 10;   
                result[p1] += sum / 10;   
            }
        }

        string str;
        for (int d : result)
            if (!(str.empty() && d == 0))
                str += to_string(d);

        return str.empty() ? "0" : str;
    }
};