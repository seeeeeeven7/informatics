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

template<class T> void updateType1(T now, T &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
	}
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
	if (a % b == 0) return b;
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

/* --------------------------------- */

int main() {
	ios;
	
	int n, s, e;
	while (cin >> n >> s >> e) {
		vector<int> x(n + 1), a(n + 1), b(n + 1), c(n + 1), d(n + 1);
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) cin >> d[i];
		// f[i][j][k] : 1 <= i <= n, 0 <= j <= i, -1 <= k <= 1
		vector<vector<vector<long long> > > f(2, vector<vector<long long> >(n + 1, vector<long long>(3, -1)));
		#define f(i, j, k) f[(i) % 2][(j)][(k) + 1]
		f(1, s != 1, (s == 1) - (e == 1)) = (s != 1) * b[1] + (e != 1) * (d[1]);
		for (int i = 1; i < n; i++) 
			for (int j = 0; j <= i; j++)
				for (int k = -1; k <= 1; k++) if (f(i, j, k) != -1) {
					if (j > 0 || j + k > 0) {
						//cout << i << ' ' << j << ' ' << k << ' ' << f(i, j, k) << endl;
						//if (i == n) continue;
						long long cost = f(i, j, k) + 1LL * (j * 2 + k) * (x[i + 1] - x[i]);
						//cout << s << ' ' << e << ' ' << i + 1 << endl;
						if (e == i + 1) {
							updateType1(cost + a[i + 1], f(i + 1, j, k - 1));
							updateType1(cost + b[i + 1], f(i + 1, j + 1, k - 1));
						}
						else if (s == i + 1) {
							updateType1(cost + c[i + 1], f(i + 1, j - 1, k + 1));
							updateType1(cost + d[i + 1], f(i + 1, j, k + 1));
						}
						else {
							if (j > 0) updateType1(cost + b[i + 1] + c[i + 1], f(i + 1, j, k));
							if (j + k > 0) updateType1(cost + a[i + 1] + d[i + 1], f(i + 1, j, k));
							if (j > 0 && j + k > 0) updateType1(cost + a[i + 1] + c[i + 1], f(i + 1, j - 1, k));
							updateType1(cost + b[i + 1] + d[i + 1], f(i + 1, j + 1, k));
						}
					}
					f(i, j, k) = -1;
				}
		cout << f(n, 0, 0) << endl;
	}
	
	return 0;
}
