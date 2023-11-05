#include <bits/stdc++.h>
using namespace std;

/* Template starts here */

#define int long long
#define ll int
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define len(a) (int)a.size()

int mo = 1000000007; // This variable may be changed later

#define ios_sync_false ios_base::sync_with_stdio(false)

const int MAXINT = 2147483647;

const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int hdx4[4] = {0, 1, 1, 1};
const int hdy4[4] = {1, 1, 0, -1};

template<class T> T stoi(string str) {
	T ret = 0;
	for (int i = 0; i < str.size(); i++) ret = ret * 10 + str[i] - '0';
	return ret;
}

template<class T> string itos(T i) {
	string ret = "";
	bool neg = false;
	if (i == 0) return "0";
	if (i < 0) {
		neg = true;
		i = -i;
	}
	while (i > 0) {
		ret = (char)('0' + (i % 10)) + ret;
		i = i / 10;
	}
	if (neg) ret = '-' + ret;
	return ret;
}

class Edge {
public:
	int src, dst;
	int val;
	Edge *next;
	Edge(int src_, int dst_, int val_, Edge *next_):src(src_), dst(dst_), val(val_), next(next_) {} 
	Edge(int src_, int dst_, Edge *next_):src(src_), dst(dst_), next(next_) {} 
};

int findF(vector<int> &f, int x) {
	if (f[x] == x) return x;
	return f[x] = findF(f, f[x]);
}

template<class T> T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);	
}

int sqr(int x) {
	return x * x;
}

double tri_sum(int x1, int y1, int x2, int y2, int x3, int y3) {
	double l1 = sqrt(1.0 * (sqr(x1 - x2) + sqr(y1 - y2)));
	double l2 = sqrt(1.0 * (sqr(x2 - x3) + sqr(y2 - y3)));
	double l3 = sqrt(1.0 * (sqr(x3 - x1) + sqr(y3 - y1)));
	double p = (l1 + l2 + l3) / 2;
	return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}

template<class T> void print1d(vector<T> &a) {
	for (T i : a) 
		cout << i << ' ';
	cout << endl;
}

template<class T> void print2d(vector<vector<T>> &a) {
	cout << "---------" << endl;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << setw(8) << setfill(' ') << a[i][j];
		}
		cout << endl;
	}
}

template<class T> void Gauss(vector<vector<T> > a, vector<T> &ans) {
	int n = a.size(), m = a[0].size() - 1;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < n; j++) if (a[j][i + 1] != 0) {
			if (a[i][i + 1] == 0) {
				for (int k = 0; k <= m; k++) swap(a[i][k], a[j][k]);
			}
		}
		for (int j = i + 1; j < n; j++) if (a[j][i + 1] != 0) {
			T p = a[j][i + 1] / a[i][i + 1];
			for (int k = 0; k <= m; k++) {
				a[j][k] = a[j][k] - a[i][k] * p;
			}
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		ans[i] = a[i][0] / a[i][i + 1];
		for (int j = 0; j < i; j++) {
			a[j][0] = a[j][0] - a[j][i + 1] * ans[i];
		}
	}
}

vector<int> string2vector(string str) {
	vector<int> ret;
	for (int i = str.length() - 1; i >= 0; i--) ret.push_back(str[i] - '0');
	return ret;
}

vector<int> mul(vector<int> a, vector<int> b) {
	vector<int> ret(a.size() + b.size() - 1, 0);
	for (unsigned int i = 0; i < a.size(); i++)
		for (unsigned int j = 0; j < b.size(); j++) {
			ret[i + j] += a[i] * b[j];
		}
	for (unsigned int i = 0; i < ret.size(); i++) {
		if (ret[i] >= 10) {
			if (i == ret.size() - 1) ret.push_back(0);
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
	}
	while (ret.size() > 1 && ret[ret.size() - 1] == 0) ret.pop_back();
	return ret;
}

void print(vector<int> a) {
	for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
}


int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

// Trie templates 
int pow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int c = pow(a, b / 2);
	c = (c * c) % mo;
	if (b & 1) c = (c * a) % mo;
	return c;
}

vector<int> fac_f(1, 1);
int fac(int n) {
	while (len(fac_f) <= n) {
		fac_f.pb(fac_f[len(fac_f) - 1] * len(fac_f) % mo);
	}
	return fac_f[n];
}

int vers(int p) {
	return pow(p, mo - 2);
}

int comb(int n, int m) {
	return ((fac(n) * vers(fac(n - m))) % mo * vers(fac(m))) % mo;
}

int perm(int n, int m) {
	return fac(n) * vers(fac(m)) % mo;
}

/* Code starts here */


const int t = 1000000;
int nex[2 * t + 10], deg[2 * t + 10], cnt[2 * t + 10];

int32_t main() {
	ios_sync_false;
	 	
#ifndef ONLINE_JUDGE
	freopen("E.in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif

	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		vector<int> ax(n), ay(n);
		for (int i = 0; i < n; i++) cin >> ax[i];
		for (int i = 0; i < n; i++) cin >> ay[i];
		int m; cin >> m;
		vector<int> bx(m), by(m);
		for (int i = 0; i < m; i++) cin >> bx[i];
		for (int i = 0; i < m; i++) cin >> by[i];

		vector<int> ai(n);
		for (int i = 0; i < n; i++) ai[i] = i;
		vector<int> bi(m);
		for (int i = 0; i < m; i++) bi[i] = i;

		sort(ai.begin(), ai.end(), [&ay](int i, int j) {
			return ay[i] > ay[j];
		});
		sort(bi.begin(), bi.end(), [&bx](int i, int j) {
			return bx[i] > bx[j];
		});

		int j = 0, y = 0;
		for (int i : ai) {
			while (j < m && bx[bi[j]] > ay[i]) {
				y = max(y, by[bi[j]]);
				j ++;
			}
			if (y > 0)
				nex[ay[i]] = t + y;
		}

		sort(ai.begin(), ai.end(), [&ax](int i, int j) {
			return ax[i] > ax[j];
		});
		sort(bi.begin(), bi.end(), [&by](int i, int j) {
			return by[i] > by[j];
		});

		j = 0; y = 0;
		for (int i : bi) {
			while (j < n && ax[ai[j]] > by[i]) {
				y = max(y, ay[ai[j]]);
				j++;
			}
			if (y > 0)
				nex[t + by[i]] = y;
		}

		set<int> idx;
		for (int i = 0; i < n; i++) cnt[ay[i]] ++;
		for (int i = 0; i < n; i++) idx.insert(ay[i]);
		for (int i = 0; i < m; i++) idx.insert(t + by[i]);

		queue<int> q;
		for (int i : idx) {
			if (nex[i] > 0)
				deg[nex[i]] ++;
		}
		for (int i : idx) 
			if (deg[i] == 0) {
				q.push(i);
			}
		int ans1 = 0, ans2 = 0, ans3 = 0;

		while (!q.empty()) {
			int i = q.front(); q.pop();
			if (nex[i] == 0) {
				// if (cnt[i] > 0) cout << i << ' ' << cnt[i] << endl;
				if (i <= t) ans1 += cnt[i];
				else ans3 += cnt[i];
				cnt[i] = 0;
			}
			else {
				cnt[nex[i]] += cnt[i];
				cnt[i] = 0;
				// cout << "T " <<  nex[i] << ' '<< cnt[nex[i]] << endl;
				if (--deg[nex[i]] == 0) {
					q.push(nex[i]);
				}
			}
		}

		for (int i : idx) if (deg[i] > 0) {
			ans2 += cnt[i];
			deg[i] = 0;
			cnt[i] = 0;
		}

		cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;

		for (int i = 0; i < n; i++) nex[ay[i]] = 0;
		for (int i = 0; i < m; i++) nex[t + by[i]] = 0;

		// for (int i = 0; i <= 2 * t; i++) cout << nex[i] << ' '; cout << endl;
		// for (int i = 0; i <= 2 * t; i++) cout << deg[i] << ' '; cout << endl;
		// for (int i = 0; i <= 2 * t; i++) cout << cnt[i] << ' '; cout << endl;

	}
		
	return 0;


}

/* 

设置精度
cout << fixed; cout.precision(6);

设置宽度
cout.width(5);

设置填充
cout.width(5); cout.fill('*');

优先队列的比较函数
struct Compare {
    bool operator()(int a, int b) {
        // 自定义比较逻辑，这里是从大到小排列
        return a < b;
    }
};

*/