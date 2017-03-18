#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

/* --------------------------------- */
 
#define ios ios_base::sync_with_stdio(false)

const int MAXINT = 2147483647;

const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};

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

bool updateType1(int now, int &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

bool updateType1(double now, double &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

class Edge {
public:
	int from, to;
	Edge *next;
	Edge(int from_, int to_, Edge *next_):from(from_), to(to_), next(next_) {} 
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

double sum(int x1, int y1, int x2, int y2, int x3, int y3) {
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

int Greater(int a, int b) {
	return a < b;
}

int GreaterPairFirst(pair<int, int> p, pair<int, int> q) {
	return p.first < q.first;
}

/* --------------------------------- */

const int MAXN = 1000000 + 10;

int n, m, k;
int a[MAXN], b[MAXN];

bool valid(int limit) {
	//cout << limit << endl;
	int pa = 0, pb = m - limit;
	for (int s = 0, t = 0; pa < n || pb < m;) {
		//cout << s << ' ' << t << ' ' << pa << ' ' << pb << ' ' << a[pa] << ' ' << b[pb] << endl;
		if (pa >= n || pb < m && a[pa] >= b[pb]) {
			if (b[pb] < t) return false;
			//cout << "B" << endl;
			pb ++;
		}
		else if (pb >= m || pa < n && a[pa] < b[pb]) {
			if (a[pa] < t) return false;
			//cout << "A" << endl;
			pa ++;
		}
		if (++s == k) {
			s = 0; t ++;
		}
	}
	return true;
}

int main() {
	ios;
	
	while (cin >> n >> m >> k) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		vector<pair<int, int> > c(m);
		for (int i = 0; i < m; i++) c[i] = make_pair(b[i], i);
		sort(a, a + n);
		sort(b, b + m, Greater);
		sort(c.begin(), c.end(), GreaterPairFirst);
		int l = 0, r = m;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (valid(mid)) l = mid;
			else r = mid - 1;
		}
		if (valid(l)) {
			cout << l << endl;
			for (int i = m - l; i < m; i ++) {
				if (i > m - l) cout << ' ';
				cout << c[i].second + 1;
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}
