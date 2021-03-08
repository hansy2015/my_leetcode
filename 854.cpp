class Solution {
public:
  int kSimilarity(string A, string B) {
    int n = (int)A.size();
    int ret = INT_MAX;
    function<void(string,int,int)> dfs = [&](string s, int d, int pos) {
      if (d > ret) return;
      if (pos == n - 1) {
        ret = min(ret, d);
        return;
      }
      int i = pos;
      while (i < n) {
        if (s[i] != A[i]) {
          break;
        }
        i++;
      }
      if (i == n) {
        ret = min(ret, d);
        return;
      }
      for (int j = i + 1; j < n; j++) {
        if (s[j] == A[i]) {
          swap(s[i], s[j]);
          dfs(s, d + 1, i + 1);
          swap(s[i], s[j]);
        }
      }
    };
    dfs(B, 0, 0);
    return ret;
  }
};