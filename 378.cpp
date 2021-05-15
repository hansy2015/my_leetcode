class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = (int)matrix.size();
    struct Point {
      int num;
      int x, y;
      Point(int _num, int _x, int _y) : num(_num), x(_x), y(_y) {}
      bool operator < (const Point& other) const {
        return num > other.num;
      }
    };
    priority_queue<Point> que;
    for (int i = 0; i < n; i++) {
      que.push(Point(matrix[i][0], i, 0));
    }
    int ret = 0;
    for (int i = 0; i < k; i++) {
      Point point = que.top();
      ret = point.num;
      que.pop();
      if (point.y < n - 1) {
        que.push(Point(matrix[point.x][point.y + 1], point.x, point.y + 1));
      }
    }
    return ret;
  } 
};