class Solution {
public:
  int trailingZeroes(int n) {
    int foo = 0;
    int bar = 0;
    auto F = [](int& num, int ner) -> int {
      int ans = 0;
      while (num % ner == 0) {
        num /= ner;
        ans++;
      }
      return ans;
    };

    for (int i = 2; i <= n; i++) {
      int t = i;
      foo += F(t, 2);
      bar += F(t, 5);
    }
    return min(foo, bar);
  }
};




class Solution {
public:
  int trailingZeroes(int n) {
    int cnt = 0;
    while (n >= 5) {
      cnt += n / 5;
      n /= 5;
    }
    return cnt;
  }
};