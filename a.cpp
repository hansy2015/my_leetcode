/*#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        bool flag = true;
        int transfrom = 1;
        string foo, bar;
        cin >> n;
        cin >> foo >> bar;
        vector<vector<int>> pre(2, vector<int>(n, 0));
        if (foo[0] == '0') {
            pre[0][0] = 1;
        } else {
            pre[1][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (foo[i] == '0') {
                pre[0][i] = pre[0][i - 1] + 1;
                pre[1][i] = pre[1][i - 1];
            } else {
                pre[1][i] = pre[1][i - 1] + 1;
                pre[0][i] = pre[0][i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (foo[i] != bar[i]) {
                if (transfrom == 0) {
                    continue;
                }
                if (pre[0][i] == pre[1][i]) {
                    transfrom ^= 1;
                } else {
                    flag = false;
                    break;
                }
            } else {
                if (transfrom == 1) {
                    continue;
                }
                if (pre[0][i] == pre[1][i]) {
                    transfrom ^= 1;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}*/

/*
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string ss;
    bool transfrom = 0;
    cin >> n >> ss;
    int c = count(ss.begin(), ss.end(), '1');
    if (c % 2 == 1 || ss[0] == '0' || ss.back() == '0') {
      cout << "NO" << "\n";
      continue;
    }
    int k = 0;
    string a, b;
    for (int i = 0; i < n; i++) {
      if (ss[i] == '1') {
        a.push_back(2 * k < c ? '(' : ')');
        b.push_back(a.back());
        k++;
      } else {
        a.push_back(transfrom ? '(' : ')');
        b.push_back(transfrom ? ')' : '(');
        transfrom ^= 1;
      }
    }
    cout << "YES" << "\n";
    cout << a << "\n" << b << "\n";
  }
  return 0; 
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        long long W;
        cin >> n >> W;
        int p = 0;
        long long s = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > W) {
                continue;
            }
            if (x >= (W + 1) / 2) {
                p = i + 1;
            } else {
                if (s < (W + 1) / 2) {
                    s += x;
                    ans.push_back(i);
                } 
            }
        }
        if (p) {
            cout << 1 << "\n" << p << "\n";
        } else if (s >= (W + 1) / 2) {
            cout << ans.size() << "\n";
            for (int i : ans) {
                cout << i + 1 << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << "\n";
        }
        
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, j = 0;
    cin >> n;
    vector<int> a(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            j++;
            for (int k = i; k <= n; k += i) {
                a[k] = j;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
        cout << 1 << " " << n << "\n";
        cout << n - 1 << " ";
        for (int i = 1; i <= n - 1; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
accumulate
*/

/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int foo = 0, bar = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			foo++;
		} else {
			bar++;
		}
	}
	if (bar >= 1) {
		bar--;
		cout << "2" << " ";
	}
	if (foo >= 1) {
		foo--;
		cout << "1" << " ";
	}
	while (bar > 0) {
		cout << "2" << " ";
		bar--;
	}
	while (foo > 0) {
		cout << "1" << " ";
		foo--;
	}
	return 0;
}

*/

/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		int a1, b1, c1;
		int a2 = 0, b2 = 0, c2 = 0;
		string s;
		cin >> n >> a1 >> b1 >> c1 >> s;
		for (char ch : s) {
			if (ch == 'R') a2++;
			else if (ch == 'P') b2++;
			else c2++;
 		}
 		if (min(a1, c2) + min(b1, a2) + min(c1, b2) >= (n + 1) / 2) {
 			cout << "YES" << endl;
 			vector<char> chars(n, '#');
 			for (int i = 0; i < n; i++) {
 				if (s[i] == 'S') {
 					if (a1 > 0) {
 						chars[i] = 'R';
 						a1--;
 					}
 				} else if (s[i] == 'R') {
 					if (b1 > 0) {
 						chars[i] = 'P';
 						b1--;
 					}
 				} else {
 					if (c1 > 0) {
 						chars[i] = 'S';
 						c1--;
 					}
 				}
 			}
 			for (int i = 0; i < n; i++) {
 				if (chars[i] == '#') {
 					if (a1 > 0) {
 						chars[i] = 'R';
 						a1--;
 					} else if (b1 > 0) {
 						chars[i] = 'P';
 						b1--;
 					} else {
 						chars[i] = 'S';
 						c1--;
 					}
 				}
 			}
 			for (char c : chars) {
 				cout << c;
 			}
 			cout << endl;
 		} else {
 			cout << "NO" << endl;
 		}
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		n += 2;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
		}
		sort(a.begin(), a.end());
		int pos = -1;
		int sum = accumulate(a.begin(), a.begin() + n - 1, 0 * 1LL);
		for (int i = 0; i < n - 1; i++) {
			if (sum - a[i] == a[n - 1]) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			if (accumulate(a.begin(), a.begin() + n - 2, 0 * 1LL) == a[n - 2]) {
				for (int i = 0; i < n - 2; i++) {
					cout << a[i] << " ";
				}
				cout << endl;
			} else {
				cout << "-1" << "\n";
			}
		} else {
			for (int i = 0; i < n - 1; i++) {
				if (i != pos) {
					cout << a[i] << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		vector<int> a(m, 0);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			a[x % m]++;
		}
		if (n == 1) {
			cout << "1" << "\n";
			continue;
		}
		for (int i = 1; i <= m / 2; i++) {
			if (i == m - i) {
				if (a[i] != 0) {
					cnt += 1;
				}
			} else {
				int foo = max(a[i], a[m - i]);
				int bar = min(a[i], a[m - i]);
				if (foo == 0) {
					continue;
				}
				if (foo == bar) {
					cnt += 1;
				} else {
					cnt += 1;
					cnt += (foo - bar - 1);
				}
			}
		}
		if (a[0]) cnt += 1;
		cout << cnt << "\n";
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) ans++;
		}
		cout << (ans + 1) / 2 << "\n";
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		if (n % 2050 != 0) {
			cout << "-1" << "\n";
			continue;
		}
		n /= 2050;
		long long ans = 0;
		while (n) {
			ans += (n % 10);
			n /= 10;
		}
		cout << ans << "\n";
	}
	return 0;
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int,int>> vec;
		vector<multiset<int>> get(n);
		vector<vector<int>> w(n, vector<int>(m));
		vector<int> it(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				vec.emplace_back(x, i);
				get[i].insert(x);
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < m; i++) {
			auto tmp = vec[i];
			w[tmp.second][it[tmp.second]++] = vec[i].first;
			for (int j = 0; j < n; j++) {
				if (j != tmp.second) {
					w[j][it[j]++] = *get[j].rbegin();
					get[j].erase(--get[j].end());
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << w[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	iota(a.begin(), a.end(), 0);
	vector<vector<int>> w(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i][i]);
		b[i] = w[i][i];
	}
	function<bool(int,int,int)> Dfs = [&](int num, int x, int y) {
		if (a[num] == 0) {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n && xx > yy && w[xx][yy] == 0) {
				w[xx][yy] = num + 1;
				a[num]--;
				if (Dfs(num, xx, yy)) {
					return true;
				}
			}
		}
		return false;
	};
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (!Dfs(b[i] - 1, i, i)) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << w[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n), c(m);
		vector<pair<int,int>> f;
		vector<int> ret(m, -1);
		unordered_map<int,vector<int>> mp;
		unordered_map<int,int> bPos;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			if (a[i] != b[i]) {
				f.emplace_back(i, b[i]);
			}
			bPos[b[i]] = i;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &c[i]);
			mp[c[i]].push_back(i);
		}
		bool flag = false;
		for (int i = 0; i < (int)f.size(); i++) {
			int p = f[i].first;
			int co = f[i].second;
			if (mp[co].empty()) {
				flag = true;
				break;
			}
			ret[mp[co].back()] = p;
			mp[co].pop_back();
		}
		if (flag) {
			cout << "NO" << "\n";
			continue;
		}
		if (ret[m - 1] == -1) {
			if (bPos.count(c[m - 1])) {
				for (int i = 0; i < m; i++) {
					if (ret[i] == -1) {
						ret[i] = bPos[c[m - 1]];
					}
				}
				cout << "YES" << "\n";
				for (int i = 0; i < m; i++) {
					cout << ret[i] + 1 << " ";
				}
				cout << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			for (int i = 0; i < m; i++) {
				if (ret[i] == -1) {
					ret[i] = ret.back();
				}
			}
			cout << "YES" << "\n";
			for (int i = 0; i < m; i++) {
				cout << ret[i] + 1 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		int mx = 0;
		cin >> n;
		unordered_map<int,int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			mp[x]++;
			mx = max(mx, mp[x]);
		}	
		cout << max(n % 2, 2 * mx - n) << endl;
		cout << "sadda" << endl;
	}
	return 0;
}


