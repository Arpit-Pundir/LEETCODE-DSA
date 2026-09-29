class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // Must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );

        dp[0][0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                vector<pair<int,int>> prev;

                if (i > 0)
                    prev.push_back({i - 1, j});

                if (j > 0)
                    prev.push_back({i, j - 1});

                for (auto [x, y] : prev) {
                    for (int balance : dp[x][y]) {

                        int newBalance = balance;

                        if (grid[i][j] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        // Balance can never become negative
                        if (newBalance >= 0)
                            dp[i][j].insert(newBalance);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
    }
};