class Solution {
public:
  bool isMatch(string s, string p) {
    int n = (int)s.size();
    int m = (int)p.size();
    auto matchs = [&](int i, int j) {
      if (i == 0) {
        return false;
      }
      return s[i - 1] == p[j - 1] || p[j - 1] == '.';
    };
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] |= dp[i][j - 2];
          if (matchs(i, j - 1)) {
            dp[i][j] |= dp[i - 1][j];
          }
        } else {
          if (matchs(i, j)) {
            dp[i][j] |= dp[i - 1][j - 1];
          }
        }
      }
    }
    return dp[n][m];
  }
};