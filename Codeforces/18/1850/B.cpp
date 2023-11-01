#include <bits/stdc++.h>
using namespace std;

/* Template starts here */

#define i64 long long
#define ll i64
#define pb push_back
#define fi first
#define se second
#define pii pair<i64,i64>
#define mp make_pair
#define len(a) (i64)a.size()

i64 mo = 1000000007; // This variable may be changed later

#define ios_sync_false ios_base::sync_with_stdio(false)

const i64 MAXINT = 2147483647;

const i64 dx4[4] = {0, 0, 1, -1};
const i64 dy4[4] = {1, -1, 0, 0};
const i64 dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const i64 dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const i64 hdx4[4] = {0, 1, 1, 1};
const i64 hdy4[4] = {1, 1, 0, -1};

template<class T> T stoi(string str) {
	T ret = 0;
	for (i64 i = 0; i < str.size(); i++) ret = ret * 10 + str[i] - '0';
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
	i64 src, dst;
	i64 val;
	Edge *next;
	Edge(i64 src_, i64 dst_, i64 val_, Edge *next_):src(src_), dst(dst_), val(val_), next(next_) {} 
	Edge(i64 src_, i64 dst_, Edge *next_):src(src_), dst(dst_), next(next_) {} 
};

i64 findF(vector<i64> &f, i64 x) {
	if (f[x] == x) return x;
	return f[x] = findF(f, f[x]);
}

template<class T> T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);	
}

i64 sqr(i64 x) {
	return x * x;
}

double tri_sum(i64 x1, i64 y1, i64 x2, i64 y2, i64 x3, i64 y3) {
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
	for (i64 i = 0; i < a.size(); i++) {
		for (i64 j = 0; j < a[i].size(); j++) {
			cout << setw(8) << setfill(' ') << a[i][j];
		}
		cout << endl;
	}
}

template<class T> void Gauss(vector<vector<T> > a, vector<T> &ans) {
	i64 n = a.size(), m = a[0].size() - 1;
	for (i64 i = 0; i < m; i++) {
		for (i64 j = i; j < n; j++) if (a[j][i + 1] != 0) {
			if (a[i][i + 1] == 0) {
				for (i64 k = 0; k <= m; k++) swap(a[i][k], a[j][k]);
			}
		}
		for (i64 j = i + 1; j < n; j++) if (a[j][i + 1] != 0) {
			T p = a[j][i + 1] / a[i][i + 1];
			for (i64 k = 0; k <= m; k++) {
				a[j][k] = a[j][k] - a[i][k] * p;
			}
		}
	}
	for (i64 i = m - 1; i >= 0; i--) {
		ans[i] = a[i][0] / a[i][i + 1];
		for (i64 j = 0; j < i; j++) {
			a[j][0] = a[j][0] - a[j][i + 1] * ans[i];
		}
	}
}

vector<i64> string2vector(string str) {
	vector<i64> ret;
	for (i64 i = str.length() - 1; i >= 0; i--) ret.push_back(str[i] - '0');
	return ret;
}

vector<i64> mul(vector<i64> a, vector<i64> b) {
	vector<i64> ret(a.size() + b.size() - 1, 0);
	for (unsigned i64 i = 0; i < a.size(); i++)
		for (unsigned i64 j = 0; j < b.size(); j++) {
			ret[i + j] += a[i] * b[j];
		}
	for (unsigned i64 i = 0; i < ret.size(); i++) {
		if (ret[i] >= 10) {
			if (i == ret.size() - 1) ret.push_back(0);
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
	}
	while (ret.size() > 1 && ret[ret.size() - 1] == 0) ret.pop_back();
	return ret;
}

void print(vector<i64> a) {
	for (i64 i = a.size() - 1; i >= 0; i--) cout << a[i];
}


i64 cross(pair<i64, i64> a, pair<i64, i64> b, pair<i64, i64> c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

// Trie templates 
i64 cnt = 0;
class TrNode {
public:
	i64 no;
	i64 value;
	vector<TrNode *> next;
	TrNode *pre;
	TrNode *parent;
	TrNode(i64 s, TrNode *parent_ = NULL):parent(parent_) {
		value = 0;
		next = vector<TrNode *>(s, NULL);
		no = ++cnt;
	}
	void addStr(string str) {
		TrNode *rt = this;
		for (unsigned i64 i = 0; i < str.length(); i++) {
			if (rt -> next[str[i] - 'a'] == NULL) {
				rt -> next[str[i] - 'a'] = new TrNode(26, this);	
			}
			rt = rt -> next[str[i] - 'a']; 
		}
		rt -> value = max(rt -> value, (i64)str.length());
	}
	void buildGraph() {
		queue<TrNode *> Q;
		pre = this;
		for (unsigned i64 i = 0; i < next.size(); i++) {
			if (next[i] != NULL) {
				Q.push(next[i]);
				next[i] -> pre = this;
			}
			else next[i] = this;
		}
		while (!Q.empty()) {
			TrNode *rt = Q.front(); Q.pop();
			for (unsigned i64 i = 0; i < rt -> next.size(); i ++) {
				if (rt -> next[i] != NULL) {
					Q.push(rt -> next[i]);
					rt -> next[i] -> pre = rt -> pre -> next[i];
					rt -> next[i] -> value = max(rt -> next[i] -> value, rt -> next[i] -> pre -> value);
				}
				else rt -> next[i] = rt -> pre -> next[i];
			}
		}
	}
	void print() {
		set<i64> s; s.insert(no);
		queue<TrNode *> Q; Q.push(this);
		while (!Q.empty()) {
			TrNode *rt = Q.front(); Q.pop();
			for (unsigned i64 i = 0; i < rt -> next.size(); i ++) {
				if (rt -> next[i] != NULL) {
					cout << rt -> no << ' ' << (char)('a' + i) << ' ' << rt -> next[i] -> no << endl;
					if (s.find(rt -> next[i] -> no) == s.end()) {
						Q.push(rt -> next[i]);
						s.insert(rt -> next[i] -> no);
					}
				}
			}
		}
	}
};

i64 pow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 c = pow(a, b / 2);
	c = (c * c) % mo;
	if (b & 1) c = (c * a) % mo;
	return c;
}

vector<i64> fac_f(1, 1);
i64 fac(i64 n) {
	while (len(fac_f) <= n) {
		fac_f.pb(fac_f[len(fac_f) - 1] * len(fac_f) % mo);
	}
	return fac_f[n];
}

i64 vers(i64 p) {
	return pow(p, mo - 2);
}

i64 comb(i64 n, i64 m) {
	return ((fac(n) * vers(fac(n - m))) % mo * vers(fac(m))) % mo;
}

i64 perm(i64 n, i64 m) {
	return fac(n) * vers(fac(m)) % mo;
}

/* Code starts here */

int32_t main() {
	ios_sync_false;
	 	
#ifndef ONLINE_JUDGE
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif

	i64 tasks; cin >> tasks;
	while (tasks --) {
		i64 n; cin >> n;
		vector<i64> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
		int ans = -1;
		for (int i = 0; i < n; i++) 
			if (a[i] <= 10)
				if (ans == -1 || b[i] > b[ans])
					ans = i;
		cout << ans + 1 << endl;
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
    bool operator()(i64 a, i64 b) {
        // 自定义比较逻辑，这里是从大到小排列
        return a < b;
    }
};

*/