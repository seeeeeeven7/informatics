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

/* --------------------------------- */
 
#define ios ios_base::sync_with_stdio(false)

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
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++) {
			ret[i + j] += a[i] * b[j];
		}
	for (int i = 0; i < ret.size(); i++) {
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

long long pow(long long a, long long b, long long mo) {
	if (b == 1) return a;
	long long m = pow(a, b / 2, mo);
	m = (m * m) % mo;
	if (b % 2 == 1) m = (m * a) % mo;
	return m;
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
		for (int i = 0; i < str.length(); i++) {
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
		for (int i = 0; i < next.size(); i++) {
			if (next[i] != NULL) {
				Q.push(next[i]);
				next[i] -> pre = this;
			}
			else next[i] = this;
		}
		while (!Q.empty()) {
			TrNode *rt = Q.front(); Q.pop();
			for (int i = 0; i < rt -> next.size(); i ++) {
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
			for (int i = 0; i < rt -> next.size(); i ++) {
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

/* --------------------------------- */

int main() {
	ios;
	
	int n;
	while (cin >> n) {
		vector<vector<int> > a(2);
		vector<int> s(2);
		for (int i = 0; i < 2; i++) {
			cin >> s[i]; a[i] = vector<int>(s[i]);
			for (int j = 0; j < s[i]; j++) cin >> a[i][j];
		}
		
		vector<vector<int> > count(2, vector<int>(n + 1, 0));
		vector<vector<int> > f(2, vector<int>(n + 1, 0));
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				count[i][j] = s[i];
		f[0][1] = f[1][1] = 1; // 1 for lost, 2 for win
		
		queue<pair<int, int> > Q;
		Q.push(make_pair(0, 1));
		Q.push(make_pair(1, 1));
		while (!Q.empty()) {
			int i = Q.front().first, j = Q.front().second; Q.pop();
			//cout << i << ' ' << j << ' ' << f[i][j] << endl;
			int ni = i ^ 1;
			for (int k = 0; k < s[ni]; k++) {
				int nj = (j - a[ni][k] + n - 1) % n + 1;
				if (f[i][j] == 1) {
					if (f[ni][nj] == 0) {
						f[ni][nj] = 2;
						Q.push(make_pair(ni, nj));
					}
				}
				else {
					if (--count[ni][nj] == 0 && f[ni][nj] == 0) {
						f[ni][nj] = 1;
						Q.push(make_pair(ni, nj));
					}
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j <= n; j++) {
				if (j > 2) cout << ' ';
				if (f[i][j] == 0) cout << "Loop";
				if (f[i][j] == 1) cout << "Lose";
				if (f[i][j] == 2) cout << "Win";
			}
			cout << endl;
		}
	}

	return 0;
}
