class Solution {
public:
    vector<string> ans;

    void solve(string current, int open, int close, int n) {
        // Complete valid combination
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(current + "(", open + 1, close, n);
        }

        // Add closing bracket only when valid
        if (close < open) {
            solve(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};