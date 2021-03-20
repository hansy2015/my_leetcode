class Solution {
public:
  int getK(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int n = (int)nums1.size();
    int m = (int)nums2.size();
    int index1 = 0, index2 = 0;
    while (true) {
      if (index1 == n) {
        return nums2[index2 + k - 1];
      }
      if (index2 == m) {
        return nums1[index1 + k - 1];
      }
      if (1 == k) {
        return min(nums1[index1], nums2[index2]);
      }
      int newIndex1 = min(index1 + k / 2 - 1, n - 1);
      int newIndex2 = min(index2 + k / 2 - 1, m - 1);
      if (nums1[newIndex1] <= nums2[newIndex2]) {
        k -= (newIndex1 - index1 + 1);
        index1 = newIndex1 + 1;
      } else {
        k -= (newIndex2 - index2 + 1);
        index2 = newIndex2 + 1;
      }
    }
    return -1;
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = (int)nums1.size() + (int)nums2.size();
    if (total % 2) {
      return getK(nums1, nums2, (total + 1) / 2);
    } else {
      int foo = getK(nums1, nums2, total / 2);
      int bar = getK(nums1, nums2, (total + 1) / 2);
      return (foo + bar) / 2.0;
    }
  }
};