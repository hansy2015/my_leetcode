class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:
    self.ans = 0
    for i in range(0, len(nums) - 2):
      self.d = nums[i + 1] - nums[i]
      for j in range(i + 1, len(nums) - 1):
        if self.d == (nums[j + 1] - nums[j]):
          self.ans += 1
          pass
        else:
          break
          pass
        pass
      pass
    pass
    return self.ans

      