class Solution {

    long long f(int i, int j, string &s, string &t,
                vector<vector<long long>> &dp) {

        // t is completely formed
        if(j == 0) {
            return 1;
        }

        // s is finished but t is still remaining
        if(i == 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if(s[i-1] == t[j-1]) {

            return dp[i][j] =
                f(i-1, j-1, s, t, dp) +
                f(i-1, j, s, t, dp);
        }

        // Characters don't match
        return dp[i][j] =
            f(i-1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(m + 1, -1)
        );

        return f(n, m, s, t, dp);
    }
};