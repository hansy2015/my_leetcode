/*
  建图后直接bfs找最短路
*/
class Solution {
public:
  bool check(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
      if (a[i] == b[j]) {
        return true;
      }
      if (a[i] < b[j]) {
        i++;
      } else {
        j++;
      }
    }
    return false;
  }
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    int n = (int)routes.size();
    vector<vector<int>> G(n);  
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (check(routes[i], routes[j])) {
          G[i].push_back(j);
          G[j].push_back(i);
        }
      }
    }
    vector<int> beg;
    unordered_set<int> end;
    for (int i = 0; i < n; i++) {
      for (int j : routes[i]) {
        if (j == source) {
          beg.push_back(i);
          break;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j : routes[i]) {
        if (j == target) {
          end.insert(i);
          break;
        }
      }
    }

    auto bfs = [&](int pos) -> int {
      queue<int> que;
      que.push(pos);
      vector<int> dp(n, 0);
      vector<int> mark(n, 0);
      mark[pos] = 1;
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (end.count(u)) {
          return dp[u];
        }
        for (int v : G[u]) {
          if (!mark[v]) {
            mark[v] = 1;
            dp[v] = dp[u] + 1;
            que.push(v);
          }
        }
      }
      return -1;
    };
    int ret = INT_MAX;
    for (int i = 0; i < (int)beg.size(); i++) {
      int tmp = bfs(beg[i]);
      if (tmp != -1) {
        ret = min(ret, tmp);
      }
    }
    if (ret == INT_MAX) {
      return -1;
    } else {
      return ret + 1;
    }
  }
};