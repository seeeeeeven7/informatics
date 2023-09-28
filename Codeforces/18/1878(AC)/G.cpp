#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

/* Template starts here */
 
long long mo = 1000000007; // This variable may be changed later

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

bool updateType1(int &ans, int now) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

bool updateType1(long long &ans, long long now) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

bool updateType1(double &ans, double now) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
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

template<class T> void print2d(vector<vector<T> > &a) {
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

long long cross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

// Trie templates 
int cnt = 0;
class TrNode {
public:
	int no;
	int value;
	vector<TrNode *> next;
	TrNode *pre;
	TrNode *parent;
	TrNode(int s, TrNode *parent_ = NULL):parent(parent_) {
		value = 0;
		next = vector<TrNode *>(s, NULL);
		no = ++cnt;
	}
	void addStr(string str) {
		TrNode *rt = this;
		for (unsigned int i = 0; i < str.length(); i++) {
			if (rt -> next[str[i] - 'a'] == NULL) {
				rt -> next[str[i] - 'a'] = new TrNode(26, this);	
			}
			rt = rt -> next[str[i] - 'a']; 
		}
		rt -> value = max(rt -> value, (int)str.length());
	}
	void buildGraph() {
		queue<TrNode *> Q;
		pre = this;
		for (unsigned int i = 0; i < next.size(); i++) {
			if (next[i] != NULL) {
				Q.push(next[i]);
				next[i] -> pre = this;
			}
			else next[i] = this;
		}
		while (!Q.empty()) {
			TrNode *rt = Q.front(); Q.pop();
			for (unsigned int i = 0; i < rt -> next.size(); i ++) {
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
		set<int> s; s.insert(no);
		queue<TrNode *> Q; Q.push(this);
		while (!Q.empty()) {
			TrNode *rt = Q.front(); Q.pop();
			for (unsigned int i = 0; i < rt -> next.size(); i ++) {
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

long long pow(long long a, long long b) {
	if (b == 1) return a;
	long long c = pow(a, b / 2);
	c = (c * c) % mo;
	if (b & 1) c = (c * a) % mo;
	return c;
}

vector<long long> fac_f(1, 1);
long long fac(long long n) {
	while (fac_f.size() <= (unsigned long long) n) {
		fac_f.push_back(fac_f[fac_f.size() - 1] * fac_f.size() % mo);
	}
	return fac_f[n];
}

long long vers(long long p) {
	return pow(p, mo - 2);
}

long long comb(long long n, long long m) {
	return ((fac(n) * vers(fac(n - m))) % mo * vers(fac(m))) % mo;
}

long long perm(long long n, long long m) {
	return fac(n) * vers(fac(m)) % mo;
}


/* Code starts here */

const int maxn = 200000 + 5;
const int maxm = 30;

int uf[maxn];
int us[maxn][maxm + 1];

void calc(vector<int> &ubtm, vector<int> &utop, int hl, int hr) {
	for (int j = 0, l, r; j <= maxm; j++) {
		l = hl, r = hr;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (us[hr][j] - us[m - 1][j] > 0) l = m;
			else r = m - 1;
		}
		ubtm[j] = (us[hr][j] - us[l - 1][j] > 0 ? l : -1);
		l = hl, r = hr;
		while (l < r) {
			int m = (l + r) / 2;
			if (us[m][j] - us[hl - 1][j] > 0) r = m;
			else l = m + 1;
		}
		utop[j] = (us[l][j] - us[hl - 1][j] > 0 ? l : -1);
	}
}

int vf[maxn];
int vbtm[maxn][maxm + 1];
int vtop[maxn][maxm + 1];

int findVF(int x) {
	if (vf[x] != x) {
		int p = vf[x];
		vf[x] = findVF(vf[x]);
//		cout << "findVF " << x << ' ' << vf[x] << endl;
//		for (int j : vbtm[x]) cout << j << ' '; cout << endl;
//		for (int j : vtop[x]) cout << j << ' '; cout << endl;
//		for (int j : vbtm[vf[x]]) cout << j << ' '; cout << endl;
//		for (int j : vtop[vf[x]]) cout << j << ' '; cout << endl;
		for (int j = 0; j <= maxm; j++) {
			if (vbtm[x][j] == -1) vbtm[x][j] = vbtm[p][j];
			if (vtop[p][j] != -1) vtop[x][j] = vtop[p][j];
		}
	}
	return vf[x];
}

int a[maxn];
int h[maxn];
int ans[maxn];

void dfs(vector<vector<int>> &e, vector<vector<pair<int, int>>> &q, vector<int> &s, int fa, int i) {
//	cout << fa << ' ' << i << ' ' << a[i] << endl;
	s[i] = 1; vf[i] = i;
	h[i] = h[fa] + 1;
	for (int j = 0; j <= maxm; j++) us[h[i]][j] = us[h[fa]][j] + ((a[i] >> j) & 1);
	
//	for (int j: us[h[i]]) cout << j << ' '; cout << endl;
	for (int j = 0; j <= maxm; j++) vbtm[i][j] = vtop[i][j] = ((a[i] >> j) & 1) ? h[i] : -1;
	
	for (auto p : q[i]) {
		if (s[p.first] == 0) continue;
		int lca = findVF(p.first);
//		cout << p.first << ' ' << p.second << ' ' << lca << endl;
		ans[p.second] = 0;
		vector<int> ubtm(maxm + 1), utop(maxm + 1);
		calc(ubtm, utop, h[lca], h[i]);
//		for (int j : vtop[p.first]) cout << j << ' '; cout << endl;
//		for (int j : vbtm[p.first]) cout << j << ' '; cout << endl;
//		for (int j : utop) cout << j << ' '; cout << endl;
//		for (int j : ubtm) cout << j << ' '; cout << endl;
		vector<pair<int, int>> pos;
		for (int j = 0; j <= maxm; j++) {
			if (ubtm[j] == -1 && vbtm[p.first][j] == -1) continue;
			ans[p.second] += 1;
			if (ubtm[j] == -1) {
				pos.push_back(make_pair(h[lca] - vbtm[p.first][j], 1));
				pos.push_back(make_pair(h[lca] - vtop[p.first][j] + 1, -1));
			}
			else if (vbtm[p.first][j] == -1) {
				pos.push_back(make_pair(utop[j] - h[lca], 1));
				pos.push_back(make_pair(ubtm[j] - h[lca] + 1, -1));
			}
			else {
				pos.push_back(make_pair(h[lca] - vbtm[p.first][j], 1));
				pos.push_back(make_pair(ubtm[j] - h[lca] + 1, -1));
			}
		}
		sort(pos.begin(), pos.end());
		int s = 0, ansmax = 0;
		for (auto p : pos) {
//			cout << p.first << ' ' << p.second << endl;
			s += p.second;
			ansmax = max(ansmax, s);
		}
		ans[p.second] += ansmax;
//		cout << "! " << i << ' ' << p.first << ' ' << p.second << ' ' << ans[p.second] << endl;
	}
	
	for (int j : e[i]) if (j != fa) {
		dfs(e, q, s, i, j);
	}
	s[i] = 2; vf[i] = fa;
}
	
int main() {
	ios_sync_false;
	 	
#ifndef ONLINE_JUDGE
    freopen("G.in", "r", stdin);
//    freopen(".out", "w", stdout);
#endif

	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<vector<int>> e(n + 1, vector<int>());
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int m; cin >> m;
		vector<vector<pair<int, int>>> q(n + 1, vector<pair<int, int>>());
		for (int i = 1; i <= m; i++) {
			int u, v; cin >> u >> v;
			q[u].push_back(make_pair(v, i));
			if (u != v) q[v].push_back(make_pair(u, i));
		}
		vector<int> s(n + 1, 0);
		dfs(e, q, s, 0, 1);
		for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
		cout << endl;
	}
 	
	return 0;
}