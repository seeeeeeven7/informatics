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

void merge(long long am1, long long ap1, long long am2, long long bm1, long long bp1, long long bm2, long long &cm1, long long &cp1, long long &cm2) {
	if (am1 == bm1) {
		if (ap1 != bp1) {
			cm1 = cm2 = am1;
			cp1 = ap1;
		}
		else {
			cm1 = am1;
			cp1 = ap1;
			cm2 = max(am2, bm2);
		}
	}
	else if (am1 > bm1) {
		cm1 = am1;
		cp1 = ap1;
		cm2 = max(am2, bm1);
	}
	else {
		cm1 = bm1;
		cp1 = bp1;
		cm2 = max(am1, bm2);
	}
}

void 

int main() {
	ios_sync_false;
	 	
#ifndef ONLINE_JUDGE
	freopen("F1.in", "r", stdin);
	freopen("F1.out", "w", stdout);
#endif
	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		vector<int> a(n), h(n);
		for (int i = 0; i < n; i++) cin >> h[i];
		for (int i = 0; i < n; i++) cin >> a[i];
		int m = 0;
		for (int i = 0; i < n; i++) m = max(m, a[i]);
		int bits = 0;
		while ((1 << (bits + 1)) <= m) bits ++;
		// cout << m << ' ' << bits << endl;
		vector<vector<long long>> m1(m * 2 + 1, vector<long long>(bits + 1, -1));
		vector<vector<long long>> p1(m * 2 + 1, vector<long long>(bits + 1, -1));
		vector<vector<long long>> m2(m * 2 + 1, vector<long long>(bits + 1, -1));
		for (int i = 0; i < n; i++) merge(m1[a[i]][0], p1[a[i]][0], m2[a[i]][0], h[i], i, -1, m1[a[i]][0], p1[a[i]][0], m2[a[i]][0]);
		for (int j = 1; j <= bits; j++) {
			for (int i = 0; i <= m; i++) {
				int k = i + (1 << (j - 1));
				merge(
					m1[i][j - 1], p1[i][j - 1], m2[i][j - 1], 
					m1[k][j - 1], p1[k][j - 1], m2[k][j - 1], 
					m1[i][j], p1[i][j], m2[i][j]
					);
				// cout << i << ' ' << j << ' ' << k << ' ' << m1[i][j] << ' ' << p1[i][j] << ' ' << m2[i][j] << endl;
			}
		}
		vector<long long> ans(n, 0);
		for (long long x = 1, j = 0; x <= m; x ++) {
			while ((1 << (j + 1)) <= x) j++;
			long long dm1 = -1, dp1 = -1, dm2 = -1;
			for (int hits = 1; hits <= (m - 1) / x + 1; hits ++) {
				long long l = (hits - 1) * x + 1, r = hits * x - (1 << j) + 1;
				long long cm1 = -1, cp1 = -1, cm2 = -1;
				merge(m1[l][j], p1[l][j], m2[l][j], m1[r][j], p1[r][j], m2[r][j], cm1, cp1, cm2);
				// cout << l << ' ' << r << ' ' << cm1 << ' ' << cp1 << ' ' << cm2 << endl;
				merge(dm1, dp1, dm2, cm1 * hits, cp1, cm2 * hits, dm1, dp1, dm2);
			}
			// cout << x << ' ' << dm1 << ' ' << dp1 << ' ' << dm2 << endl;
			ans[dp1] = max(ans[dp1], dm1 - max(dm2, 0LL));
		}
		for (long long i : ans) cout << i << ' ';
		cout << endl;
	}
	return 0;
}
