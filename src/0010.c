bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    bool dp[m + 1][n + 1];

    memset(dp, 0, sizeof(dp));
    dp[m][n] = true;

    for (int i = m; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            bool match = i < m && (p[j] == '.' || p[j] == s[i]);

            if (j + 1 < n && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
            } else {
                dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}