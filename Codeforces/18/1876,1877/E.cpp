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

long long mo = 998244353; // This variable may be changed later

#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair

#define ios_sync_false ios_base::sync_with_stdio(false)

const int MAXINT = 2147483647;

const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int hdx4[4] = {0, 1, 1, 1};
const int hdy4[4] = {1, 1, 0, -1};

void print1d(vector<int> &a) {
	for (int i : a) 
		cout << i << ' ';
	cout << endl;
}

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
	if (b == 0) return 1;
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

int main() {
	ios_sync_false;
	 	
#ifndef ONLINE_JUDGE
	freopen("E.in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif

	int n; 
	while (cin >> n) {
		vector<int> a(n + 1), b(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; 
			b[a[i]] ++;
		}
		queue<int> q;
		vector<int> ans(n + 1, 0);
		for (int i = 1; i <= n; i++)
			if (b[i] == 0) {
				q.push(i);
			}
		while (!q.empty()) {
			int i = q.front(); q.pop();
			if (ans[i] == 0) ans[a[i]] = 1;
			if (--b[a[i]] == 0) {
				q.push(a[i]);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] > 0 && ans[i] > 0) {
				b[i] --;
				if (a[i] != i) {
					for (int j = a[i], k = ans[i] ^ 1; j != i; j = a[j]) {
						b[j] --;
						ans[j] = k;
						k = k ^ 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] > 0) {
				b[i] --;
				if (a[i] != i) {
					for (int j = a[i], k = ans[i] ^ 1; j != i; j = a[j]) {
						b[j] --;
						ans[j] = k;
						k = k ^ 1;
					}
				}
			}
		}
		bool valid = true;
		int count = 0;
		for (int i = 1; i <= n; i++) if (ans[i] == 0) {
			if (ans[a[i]] == 0) valid = false;
			count ++;
		}
		if (valid) {
			cout << count << endl;
			for (int i = 1; i <= n; i++) if (ans[i] == 0) cout << a[i] << ' ';
			cout << endl;
		}
		else cout << -1 << endl;
	}
		
	return 0;
}
