class Solution {
public:
  int majorityElement(vector<int>& nums) {
    // Boyer-Moore 投票算法
    // 如果我们把多数元素记为+1,把其他数记为-1，把他们全部加起来一定大于0
    int moreNum = nums[0];
    int ans = 1;
    for (int i = 0; i < (int)nums.size(); i++) {
    	if (nums[i] == moreNum) {
    		ans++;
    	} else {
    		ans--;
    		if (ans == 0) {
    			moreNum = nums[i];
    			ans = 1;
    		}
    	}
    }
    return moreNum;
  }
};