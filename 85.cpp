class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int m = (int)matrix.size();
    if (0 == m) {
      return 0;
    }
    int n = (int)matrix[0].size();
    int maxarea = 0;
    vector<int> left(n);
    vector<int> right(n, n - 1);
    vector<int> height(n);

    for (int i = 0; i < m; i++) {
      int cur_left = 0, cur_right = n - 1;
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          height[j]++;
        } else {
          height[j] = 0;
        }
      }

      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          left[j] = max(left[j], cur_left);
        } else {
          left[j] = 0;
          cur_left = j + 1;
        }
      }

      for (int j = n - 1; j >= 0; j--) {
        if (matrix[i][j] == '1') {
          right[j] = min(right[j], cur_right);
        } else {
          right[j] = n - 1;
          cur_right = j - 1;
        }
      }

      for (int j = 0; j < n; j++) {
        maxarea = max(maxarea, (right[j] - left[j] + 1) * height[j]);
      }
    }
    return maxarea;
  }
};