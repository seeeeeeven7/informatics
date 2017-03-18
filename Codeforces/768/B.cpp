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

/* --------------------------------- */

vector<long long> a, b, c, d;

long long calc(long long n) {
	long long s = 0;
	for (int i = 0; i < a.size(); i++) {
		if (n >= c[i + 1]) {
			s += d[i + 1];
			n -= c[i + 1];
			if (n > 0) {
				s += b[i];
				n -= 1;
			}
		}
	//	cout << i << ' ' << n << ' ' << s << endl;
	}
	return s;
}

int main() {
	ios;
	
	long long n, l, r;
	cin >> n >> l >> r;
	a.push_back(n);
	b.push_back(n % 2);
	for (int i = 0; a[i] > 1; i++) {
		a.push_back(a[i] / 2);
		b.push_back(a[i] / 2 % 2);
	}
	c = vector<long long>(a.size() + 1); c[a.size()] = 0;
	d = vector<long long>(a.size() + 1); d[a.size()] = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		c[i] = 2 * c[i + 1] + 1;
		d[i] = 2 * d[i + 1] + b[i];
	}
	cout << calc(r) - calc(l - 1);
	
	return 0;
}
