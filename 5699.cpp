const int INF = (int)1e9 + 10;
const int mod = (int)1e9 + 7;
class Solution {
public:
  struct node {
    int id, dist;
    node() {}
    node(int _id, int _dist) : id(_id), dist(_dist) {}
    bool operator< (const node& a) const {
      return dist > a.dist;
    }
  };
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<vector<node>> G(n + 1);
    vector<int> dis(n + 1, INF);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
    dis[n] = 0;
    node a(n, 0);
    priority_queue<node> que;
    que.push(a);
    while (!que.empty()) {
      a = que.top();
      que.pop();
      for (const auto& b : G[a.id]) {
        if (dis[b.id] > a.dist + b.dist) {
          dis[b.id] = a.dist + b.dist;
          que.push(node(b.id, dis[b.id]));
        }
      }
    }
    
    vector<int> index(n);
    iota(index.begin(), index.end(), 1);
    sort(index.begin(), index.end(), [&](int x, int y){return dis[x] > dis[y];});
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i : index) {
      for (const auto& b : G[i]) {
        if (dis[i] > dis[b.id]) {
          dp[b.id] = (dp[b.id] + dp[i]) % mod;
        }
      }
    }
    return dp[n];
  }
};