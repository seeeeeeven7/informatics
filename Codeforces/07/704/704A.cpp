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

void updateType1(int now, int &ans) {
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
	
	int n, q;
	cin >> n >> q;
	
	vector<int> count(n + 1, 0);
	vector<int> read(n + 1, 0);
	vector<int> nots;
	int ans = 0, j = 0;
	
	for (int i = 1; i <= q; i ++) {
		int type, key;
		cin >> type >> key;
		if (type == 1) {
			count[key] ++;
			nots.push_back(key);
			ans ++;
		}
		else if (type == 2) {
			ans -= count[key];
			count[key] = 0;
			read[key] = nots.size();
		}
		else if (type == 3) {
			for (; j < key; j ++) {
				int x = nots[j];
				if (read[x] <= j) {
					count[x] --;
					ans --;
				}
			}
		}
		cout << ans << endl;	
	}
	
	return 0;
}
