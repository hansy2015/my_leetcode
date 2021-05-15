class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[i] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
    }
    vector<int> ret;
    ret.push_back(dq.front());
    for (int i = k; i < (int)nums.size(); i++) {
      if (nums[i - k] == dq.front()) dq.pop_front();
      while (!dq.empty() && nums[i] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
      ret.push_back(dq.front());
    }
    return ret;
  }
};