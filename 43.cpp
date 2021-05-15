class Solution {
public:
  string multiply(string num1, string num2) {
    int n = (int)num1.size();
    int m = (int)num2.size();
    vector<int> ans(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
    	int foo, bar;
    	foo = num1[i] - '0';
    	for (int j = m - 1; j >= 0; j--) {
    		bar = num2[j] - '0';
    		ans[i + j + 1] += (foo * bar);
    	}
    }
    for (int i = n + m - 1; i >= 1; i--) {
    	ans[i - 1] += (ans[i] / 10);
    	ans[i] %= 10; 
    }
    int i = 0;
    string ret = ""
    while (i < n + m && ans[i] == 0) i++;
    while (i < n + m) {
    	ret += (ans[i] + '0');
    	i++;
    }
    if (ret == "") ret = "0";
    return ret;
  }
};