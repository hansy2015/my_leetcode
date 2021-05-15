class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int ret = 0;
    auto Dfs = [&](auto& self, int pos, int tar) -> void {
      if (pos == (int)nums.size()) {
        if (tar == target) {
          ret++;
        }
        return;
      }
      self(self, pos + 1, tar - nums[pos]);
      self(self, pos + 1, tar + nums[pos]);
      return;
    };
    Dfs(Dfs, 0, 0);
    return ret;
  }
};